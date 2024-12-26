#pragma once
/*
- semaphore : max 4, initial 4

- function thread_task (int id):
	- acquire semaphore
	- print "working"
	- sleep for 2s
	- print id + finished
	- release 

for_main:
	// TODO: check if you can accomplish with jthread
	- vector of thread
	- reserve 10
	- emplace_back the thread_task, i

	- range-based for and join
*/
#include <syncstream>
#include <iostream>
#include <print>
#include <chrono>
#include <semaphore>
#include <thread>
#include <vector>

using namespace std::literals;

std::counting_semaphore<4> g_counting_semaphore{ 4 };

auto sync_out(std::ostream& ostream = std::cout)
{
	return std::osyncstream{ ostream };
}

void thread_task(int id)
{
	g_counting_semaphore.acquire();
	sync_out() << std::format("thread {} is working...\n", id);
	std::this_thread::sleep_for(2s);
	sync_out() << std::format("thread {} finished!\n", id);
	g_counting_semaphore.release();
}

void for_main()
{
	constexpr std::size_t THREAD_POOL_SIZE{ 10 };
	std::vector<std::thread> thread_vector;
	thread_vector.reserve(THREAD_POOL_SIZE);

	for (std::size_t i{ 0 }; i < THREAD_POOL_SIZE; ++i)
	{
		thread_vector.emplace_back(thread_task, i);
	}

	for (auto& thread : thread_vector)
	{
		if (thread.joinable()) { thread.join(); }
	}
}