#pragma once
/*
- instantiate a global semaphore with a max count of 3 and an initial count of 3

- function worker:
	- returns void
	- takes an int id
	- body: // TODO: May need to sync_stream it
		- acquire the semaphore, may block if value is zero
		- std::cout << "Thread " << id << " is accessing the resource.\n";
		- sleep for 1 second
		- std::cout << "Thread " << id << " is releasing the resource.\n";
		- release the semaphore

void for_main:
	- c-style array of jthread (size 5)
	- for i = 0 to 5
		- assigned to ith element worker, i

	- l-value reference range-based for:
		- if joinable join
*/
#include <syncstream>
#include <iostream>
#include <thread>
#include <semaphore>
#include <print>
#include <chrono>

using namespace std::literals;

std::counting_semaphore<3> g_counting_semaphore{ 3 };

auto sync_out(std::ostream& ostream = std::cout)
{
	return std::osyncstream{ ostream };
}

void worker(int id)
{
	// acquire the semaphore, may block if value is zero
	g_counting_semaphore.acquire();
	sync_out() << "Thread " << id << " is accessing the resource.\n" << std::flush_emit;
	
	std::this_thread::sleep_for(1s);

	sync_out() << "Thread " << id << " is releasing the resource.\n" << std::flush_emit;
	g_counting_semaphore.release();
}


void for_main()
{
	std::thread threads[5];

	for (int i{ 0 }; i < 5; ++i)
	{
		threads[i] = std::thread{ worker, i };
	}

	for (auto& thread : threads)
	{
		if (thread.joinable())
		{
			thread.join();
		}
	}
}