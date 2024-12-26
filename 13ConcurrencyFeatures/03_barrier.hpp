#pragma once
/*

void for_main:
	- create a vector of values double from 1.0 to 8.0 (see if you can iota this)

	// define a lambda function that prints all values
	- auto define 'print_function_completion_function':
		- takes 'values' by reference
		- no arguments
		- marked as noexcept
		- body:
			auto range-based for over values
				- print with formatting :7.5
			- std::println()

	- call print_function_completion_function for the initial values

	// initialize a barrier that prints the values when all threads have done their computations
	std::barrier all_done_barrier:
		- pass in the int value of the size of 'values'
		- pass in the completion function

	- declare a vector of jthreads

	- loop over size_t 0 to values.size
		push back:
			- jthread with lambda:
				- init capture: indx by value, values and barrier by reference
				- body:
					- loop int from 0 to 5
					- reassign the square root to values
					- call arrive_and_wait to synchronize with other threads
*/
#include <iostream>
#include <print>
#include <thread>
#include <barrier>
#include <vector>
#include <ranges>

void for_main()
{
	//auto iota = std::views::iota(1, 9);
	//std::vector<double> values{ iota.begin(), iota.end() };

	std::vector values{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

	auto print_values_completion_function = [&values]() noexcept
		{
			for (auto value : values)
			{
				std::cout << std::format("{:<7.5} ", value);
				//std::print("{:<7.5} ", value);
			}
			std::cout << std::endl;
		};

	// print with initial values
	print_values_completion_function();

	// initialize a barrier that prints the values when all threads have done their computations
	std::barrier sqrt_barrier{ std::ssize(values), print_values_completion_function };

	std::vector<std::jthread> jthread_vector;

	for (std::size_t idx{ 0 }; idx < values.size(); ++idx)
	{
		jthread_vector.push_back(
			std::jthread{
				[idx, &values, &sqrt_barrier]
				{
					for (int i{0}; i < 5; ++i)
					{
						values[idx] = std::sqrt(values[idx]);
						sqrt_barrier.arrive_and_wait();
					}
				}
		});
	}
}