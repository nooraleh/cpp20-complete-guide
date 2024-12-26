#pragma once
/*
void for_main:
	- declare a queue of char 'values'
	- declare a mutex 'values_mutex'

	- for i 0 to 1'000
		push back static_cast<char>('a' + (i % ('z'-'a' + 1)))

	- constexpr int NUM_THREADS = 10
	- instantiate a counting_semaphore with max_value of NUM_THREADS
		and initial value of 0 'enabled_counting_semaphore'

	// create and start all threads of the pool
	declare a vector of jthread 'pool'

	for int idx = 0; idx < NUM_THREADS; ++idx
		- instantiate a jthread with lambda:
			- init capture: idx by value, semaphore by reference,
				valeus by reference, values_mutex by reference
			- argument list: stop_token by copy
			- body:
				- while the stop_token's stop isn't requested
					- acquire the semaphore

					- declare local char 'val'
					- new scope
						- scoped_lock on the values_mutex
						- assign the front of values to 'val'
						- pop values

					// print the value 10 times
					- for int i = 0; i < 10
						- put val to cout and then flush
						- auto dur = 130ms * ((idx % 3) + 1);
						- sleep for 'dur'

					// remove 'this_thread' from the set of enabled threads
					- release the semaphore

		- push back the moved from jthread to the pool

	- std::cout << "== wait 2 seconds (no thread enabled)\n" << std::flush;
	- std::this_thread::sleep_for(2s)

	// enable 3 concurrent threads:
	- std::cout << "== enable 3 parallel threads\n" << std::flush;
	- enabled.release(3);
	- std::this_thread::sleep_for(2s);

	// enable 2 more concurrent threads:
	- std::cout << "\n== enable 2 more parallel threads\n" << std::flush;
	- enabled.release(2);
	- std::this_thread::sleep_for(2s);

	// Normally we would run forever, but let’s end the program here:
	- std::cout << "\n== stop processing\n" << std::flush;
	- for (auto& t : pool)
		{
			t.request_stop();
		}
*/
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <vector>
#include <queue>
#include <mutex>

using namespace std::literals;

void for_main()
{
	std::queue<char> values;
	std::mutex values_mutex;

	for (int i{ 0 }; i < 1'000; ++i)
	{
		values.push(static_cast<char>('a' + (i % ('z' - 'a' + 1))));
	}

	constexpr int NUM_THREADS{ 10 };

	std::counting_semaphore<NUM_THREADS> enabled_counting_semaphore{ 0 };
	
	// create and start all threads of the pool
	std::vector<std::jthread> pool; pool.reserve(std::size_t{ NUM_THREADS });

	for (int idx{ 0 }; idx < NUM_THREADS; ++idx)
	{
		std::jthread jt{
			[idx, &enabled_counting_semaphore, &values, &values_mutex](std::stop_token stop_token)
			{
				while (not stop_token.stop_requested())
				{
					enabled_counting_semaphore.acquire();

					char val;
					{
						std::scoped_lock scoped_lock{ values_mutex };
						val = values.front();
						values.pop();
					}

					for (int i{ 0 }; i < 10; ++i)
					{
						std::cout.put(val).flush();
						auto dur = 130ms * ((idx % 3) + 1);
						std::this_thread::sleep_for(dur);
					}

					enabled_counting_semaphore.release();
				}
			}
		};

		pool.push_back(std::move(jt));
	}

	std::cout << "== wait 2 seconds (no thread enabled)\n" << std::flush;
	std::this_thread::sleep_for(2s);

	std::cout << "== enable 3 parallel threads\n" << std::flush;
	enabled_counting_semaphore.release(3);
	std::this_thread::sleep_for(2s);

	std::cout << "\n== enable 2 more parallel threads\n" << std::flush;
	enabled_counting_semaphore.release(2);
	std::this_thread::sleep_for(2s);

	// Normally we would run forever, but let’s end the program here:
	std::cout << "\n== stop processing\n" << std::flush;

	for (auto& thread : pool)
	{
		thread.request_stop();
	}
}