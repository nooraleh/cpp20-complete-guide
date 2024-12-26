#pragma once
/*
- global mutex g_mutex;
- global condition_variable
- string g_data
- bool g_ready false
- bool g_processed false

function work (std::function(void())):
	// wait until main() sends data
	- unique_lock on the global_mutex
	- condition_variable wait call:
		- pass in the unique_lock
		- simple lambda with returns g_ready

	// after the wait, we own the lock
	- print "Worker thread is processing data\n";
	- add " after processing" to g_data

	// send data back to main()
	- g_process true
	- print "Worker thread signals data processing completed";

	// manual unlocking is done before notifying, to avoid waking up
	// the waiting thread only to block again (see notify_one for details)
	unlock the unique_lock
	notify one on the global condition_variable

void for_main:
	- initialize a thread with 'work' function

	- copy assign g_data with "Example data";

	// send data to the worker thread
	- new scope
		- lock_guard on the global mutex
		- set ready to true
		- print "main() signals data ready for processing\n"
	- notify one on the condition_variable

	// wait for the worker
	- new scope
		- unique_lock on the global mutex
		- wait on the condition variable
			- pass in the unique_lock,
			- simple lambda predicate returns g_processed.
	- print "Back in main(), data = " << data << '\n';

	- call join on the thread
*/
#include <mutex>
#include <format>
#include <string>
#include <print>

std::mutex g_mutex;
std::condition_variable g_condition_variable;
std::string g_data;
bool g_ready{ false };
bool g_processed{ false };

void work()
{
	// wait until main() sends data
	std::unique_lock unique_lock{ g_mutex };
	g_condition_variable.wait(unique_lock, [] {return g_ready; });

	// after the wait, we own the lock
	std::println("Worker thread is processing data");
	g_data += " after processing";

	// send data back to main()
	g_processed = true;
	std::println("Worker thread signals data processing completed");
	
	// manual unlocking is done before notifying, to avoid waking up
	// the waiting thread only to block again (see notify_one for details)
	unique_lock.unlock();
	g_condition_variable.notify_one();
}

void for_main()
{
	std::thread thread{ work };
	g_data = "Example data";

	// send data to the worker thread
	{
		std::lock_guard lock_guard{g_mutex};
		g_ready = true;
		std::println("main() signals data ready for processing");
	}
	g_condition_variable.notify_one();

	// wait for the worker
	{
		std::unique_lock unique_lock{g_mutex};
		g_condition_variable.wait(unique_lock, [] {return g_processed; });
	}
	std::println("Back in main(), g_data = {}", g_data);

	if (thread.joinable())
	{
		thread.join();
	}
}