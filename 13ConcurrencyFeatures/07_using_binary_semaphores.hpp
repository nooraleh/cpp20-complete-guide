#pragma once
/*
void for_main:
	- declare int shared_data

	// signal there is data to process
	- instantiate a binary_semaphore 'data_ready' with 0

	// signal processing is done
	- instantiate a binary_semaphore 'data_done' with 0

	// start threads to read and process values by value
	- spawn a jthread 'process' with lambda:
		- init-capture: capture what you need
		- argument list: stop_token
		- body:
			- while the stop_token stop isn't requested
				- if trying to acquire 'data_ready' for 1s works:
					- int data = shared_data;

					// process it
					std::cout << "[process] read " << data << std::endl;
					std::this_thread::sleep_for(data * 0.5s);
					std::cout << "[process] done" << std::endl;

					- signal processing is done by calling 'release' on 'data_done'

				- else:
					std::cout << "[process] timeout" << std::endl;


	- for int i 0 up to 10
		// store next value
		std::cout << "[main] store " << i << std::endl;
		sharedData = i;

		- signal to start processing by release 'data_ready'

		- wait until processing is done by a blocking 'acquire' on data_done
		std::cout << "[main] processing done\n" << std::endl;
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <semaphore>

using namespace std::literals;

void for_main()
{
	int shared_data;

	// signal there is data to process
	std::binary_semaphore data_ready{ 0 };

	// signal data processing is done
	std::binary_semaphore data_done{ 0 };

	std::jthread process{
		[&data_ready, &data_done, &shared_data](std::stop_token stop_token)
		{
			while (not stop_token.stop_requested())
			{
				if (data_ready.try_acquire_for(1s))
				{
					int data = shared_data;

					std::cout << "[process] read " << data << std::endl;
					std::this_thread::sleep_for(data * 0.5s);
					std::cout << "[process] done" << std::endl;
					data_done.release();
				}
				else
				{
					std::cout << "[process] timeout" << std::endl;
				}
			}
		}
	};

	for (int i{ 0 }; i < 10; ++i)
	{
		// store the next value
		std::cout << "[main] store " << i << std::endl;
		shared_data = i;

		// signal to start processing by releasing `data_ready`
		data_ready.release();

		// wait until processing is done by a blocking `acquire` on data_done
		data_done.acquire();
		std::cout << "[main] processing done\n" << std::endl;
	}
}