#pragma once
/*
void for_main:
	- make a constexpr size_t for the number of threads to 10
	
	// initialize latch to start the threads when all of them have been initialized:
	-- instantiate a std::latch 'all_ready_latch' of initial value of 10

	- declare a vector of jthreads
	- loop i = 0 to number of threads
		- instantiate a jthread:
			- lambda:
				- init capture, i by value, reference to latch
				- body:
					// initialize each thread (simulate to take varying times):
					- sleep the thread for 100ms multiplied by i

					// synchronize threads so that all start together here:
					- call arrive and wait on the latch to countdown and block at the same time

					// perform whatever the thread does
					// (loop printing its index):
					- for i = 0; i < 10 ++ i
						- put the static cast of '0' + i to cout, flush in one method chain
						- sleep the thread for 50ms

		- move the thread to the push_back of your jthread_vector
*/
#include <chrono>
#include <print>
#include <thread>
#include <vector>
#include <latch>
#include <iostream>

using namespace std::literals;

void for_main()
{
	constexpr std::size_t THREAD_COUNT{ 10 };

	// initialize latch to start the threads when all of them have been initialized:
	std::latch all_ready_latch{ THREAD_COUNT };

	std::vector<std::jthread> jthread_vector;

	for (int i{ 0 }; i < THREAD_COUNT; ++i)
	{
		std::jthread jt{
			[i, &all_ready_latch]
			{
				// initialize each thread (simulate to take varying times)
				std::this_thread::sleep_for(i * 100ms);

				// synchronize threads so that all start together here:
				all_ready_latch.arrive_and_wait();

				// perform whatever the thread does
				for (int j{ 0 }; j < 10; ++j)
				{
					std::cout.put(static_cast<char>('0'+i));
					std::this_thread::sleep_for(50ms);
				}
			}
		};

		jthread_vector.push_back(std::move(jt));
	}
}