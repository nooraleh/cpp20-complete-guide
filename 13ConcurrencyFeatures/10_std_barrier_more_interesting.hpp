#pragma once
/*
Use std::barriers to get this output

Starting...
  Anil worked
  Carl worked
  Busara worked
... done
Cleaning up...
  Busara cleaned
  Carl cleaned
  Anil cleaned
... done

void for_main:
	- define const auto workers {"Anil", "Busara", "Carl"};

	- auto lambda 'on_completion'
		- empty capture
		- empty argument list
		- mark as noexcept
		- body:
			- assign to static auto 'phas'
				"... done\n"
				"Cleaning up...\n";
			- cout phase
			phase = "... done\n";

	- instantiation a barrier with ssize workers and the 'on_completion' lambda 'worker_barrier'


	- define a 'work' auto lambda:
		- capture list - take what you need by ref
		- argument list -  std::string name
		- body:
			- std::string product = "  {} worked\n", name
			- sync_out() << product;
			- worker_barrier.arrive_and_wait()

			- product = "  {} cleaned\n", name
			- sync_out() << product;
			- worker_barrier.arrive_and_wait()

	- cout "Starting...\n";
	- vector of jthread
	- reserve the size of the workers
	- const auto& on the workers
		- emplace back the work lambda, current worker
*/
#include <iostream>
#include <print>
#include <thread>
#include <syncstream>
#include <barrier>
#include <string>
#include <format>
#include <vector>
#include <chrono>

using namespace std::literals;

auto sync_out(std::ostream& ostream = std::cout)
{
	return std::osyncstream{ ostream };
}


void for_main()
{
	const auto workers = { "Anil", "Busara", "Carl" };

	auto on_completion = []() noexcept {
		// locking not needed in the section of code of the 'completion_function'
		static auto phase =
			"... done\n"
			"Cleaning up...\n";

		std::cout << phase << '\n';

		phase = "... done\n";
		};

	std::barrier worker_barrier{ std::ssize(workers), on_completion };

	auto work = [&worker_barrier](std::string name)
		{
			std::string product = std::format("  {} worked\n", name);
			std::this_thread::sleep_for(1s * std::size(name));

			sync_out() << product;

			// block at this point 'wait' and decrement the intial expected counter 'arrive'
			worker_barrier.arrive_and_wait();

			product = std::format("  {} cleaned\n", name);
			sync_out() << product;

			worker_barrier.arrive_and_wait();
		};

	std::println("Starting...");

	std::vector<std::jthread> jthread_vector;
	jthread_vector.reserve(std::ssize(workers));

	for (const auto& worker : workers)
	{
		jthread_vector.emplace_back(work, worker);
	}
}