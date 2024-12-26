#pragma once
/*
void for_main:
	- create an array of 1'000 int called 'values'
	- use std::fill_n to fill 'values' with literal 100

	- declare a stop_source 'common_stop_source'
	- instantiation a stop_token 'common_stop_token' with common_stop_source.get_token()

	- declare a vector of jthreads
	- reserve 9

	- for int i 0 to 9
		- push back a pr-value jthread
			- lambda:
				- init capture: 'values' by reference
				- argument list: stop_token
				- body:
					- instantiate a mersenne twister out of a pr-value random-device
					- instantiation a uniform_int_distribution with args 0, values.size -1

					- while we haven't received a stop request
						- randomly generate an int index value

						// enable atomic access to the value with the index:
						- instantiate an atomic_ref 'val' based on indexing 'values' with the index
						// ^^ double check std::array<>::operator[] returns a reference
						// ^^ let CTAD do it's thing

						// and use it
						- pre-fix decrement 'val'

						- if val <= 0
							std::cout << std::format("index {} is zero\n", idx);

				- pass in that common_stop_token

	- sleep the thread for 0.5 seconds
	- std::cout << "\nSTOP\n";
	- request a stop from the 'common_stop_source'
*/
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <array>
#include <algorithm>

using namespace std::literals;

void for_main()
{
	std::array<int, 1'000> values;
	std::fill_n(values.begin(), values.size(), 100);

	std::stop_source common_stop_source;
	std::stop_token common_stop_token{ common_stop_source.get_token() };

	constexpr int THREAD_COUNT{ 9 };
	std::vector<std::jthread> jthread_vector;
	jthread_vector.reserve(THREAD_COUNT);

	for (int i{ 0 }; i < THREAD_COUNT; ++i)
	{
		jthread_vector.push_back(
			std::jthread{
				[&values](std::stop_token stop_token)
				{
					std::mt19937 mersenne_twister{std::random_device{}()};
					std::uniform_int_distribution uniform_int_distribution{ std::size_t{0}, values.size() - 1 };

					while (not stop_token.stop_requested())
					{
						auto idx = uniform_int_distribution(mersenne_twister);

						// enable atomic access to the value with the index
						// note that different threads of this program DO NOT use the same std::atomic_ref
						// objects. That is fine as std::atomic_ref<> guarantees that all concurrent access to 
						// a specific object through any std::atomic_ref<> created for it is synchronised.

						// so if two threads happen to reference the same indexed value in memory - access
						// is synchronised.
						std::atomic_ref value_atomic_ref{ values[idx] };

						// decrements the value atomically
						--value_atomic_ref;

						// loads the value atomically to compare it with 0
						if (value_atomic_ref.load() <= 0)
						{
							std::cout << std::format("index {} is zero\n", idx);
						}
					}
				} ,
				common_stop_token
			}
		);
	}

	std::this_thread::sleep_for(0.5s);
	std::cout << "\nSTOP\n";
	common_stop_source.request_stop();
}