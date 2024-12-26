#pragma once
/*
- global condition_variable_any
- global mutex
- global bool flag 'ready' set to false


function worker:
	- takes a stop_token by copy
	- returns void
	- body:
		- unique locks the global mutex
		- print "Worker is waiting...\n";
		- call 'wait' on the global condition variable:
			- pass the unique lock
			- pass the stop token
			- simply lambda with returns global 'ready' flag

		- if the stop_token stop was requested
			- print "Worker was stopped before being notified!\n";
		- else:
			- print "Worker received notification and is proceeding!\n";

void for_main:
	- instantiate a stop_source
	- instantiate a jthread with the 'worker_function, stop_source.get_token()'
	- sleep the thread for two seconds

	// option 1 - notify the worker
	- new scope
		- lock guard the mutex
		- set ready to true

	- call 'notify_all' on the global condition_variable_any variable

	// option 2 - request a stop
	// stop_source.request_stop()

	TODO: with and without joining the thread
*/
#include <print>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std::literals;

std::condition_variable_any g_condition_variable_any;
std::mutex g_mutex;
bool g_ready{ false };

void worker(std::stop_token stop_token)
{
	std::unique_lock unique_lock{ g_mutex };
	std::println("Worker is waiting...");

	g_condition_variable_any.wait(unique_lock, stop_token, [] { return g_ready; });

	if (stop_token.stop_requested())
	{
		std::println("Worker was stopped before being notified!");
	}
	else
	{
		std::println("Worker received notification and is proceeding!");
	}
}

void for_main()
{
	std::stop_source stop_source;
	std::jthread jthread{worker, stop_source.get_token()};

	std::this_thread::sleep_for(2s);

	// option 1 - notify the worker
	//{
	//	std::lock_guard lock_guard{ g_mutex };
	//	g_ready = true;
	//}

	//g_condition_variable_any.notify_all();

	// option 2 - request a stop
	stop_source.request_stop();

	// jthread.join();
}