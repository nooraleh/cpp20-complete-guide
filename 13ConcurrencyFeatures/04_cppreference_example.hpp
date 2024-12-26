#pragma once
/*

- instantiate two binary_semaphores:
	1. signal_main_to_thread_semaphore with initial value of 0
	2. signal_thread_to_main_semaphore with initial value of 0

function thread_proc:
	- returns void
	- argument list: void
	- body:
		- acquire the signal_main_to_thread

		- print "[thread] Got the signal\n"

		- sleep for three seconds

		- print "[thread] Send the signal\n";

		- release signal_thread_to_main_semaphore

void for_main:
	- instantiate a thread with thread_proc

	- print "[main] Send the signal\n"

	- release the signal_main_to_thread_semaphore

	- acquire the signal_thread_to_main_semaphore

	- print "[main] Got the signal\n"

	- join the thread
*/
#include <semaphore>
#include <print>
#include <chrono>
#include <thread>

using namespace std::literals;

std::binary_semaphore signal_main_to_thread_semaphore{ 0 }, signal_thread_to_main_semaphore{ 0 };

void function_proc()
{
	std::println("[thread] waiting for signal from [main]");
	signal_main_to_thread_semaphore.acquire();
	std::println("[thread] got the signal from [main]");

	std::this_thread::sleep_for(3s);

	std::println("[thread] sending signal to [main]");

	signal_thread_to_main_semaphore.release();
}


void for_main()
{
	std::jthread jthread{ function_proc };

	std::println("[main] sending signal to [thread]");
	signal_main_to_thread_semaphore.release();

	std::println("[main] waiting for signal from [thread]");
	signal_thread_to_main_semaphore.acquire();

	std::println("[main] got the signal from [thread]");
}