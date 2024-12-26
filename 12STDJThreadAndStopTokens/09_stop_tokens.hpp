#pragma once
/*
- sync_out function:
	- returns auto
	- takes an ostream reference 'stream' ( by default takes std::cout)
	- body:
		- returns an osyncstream initialized with 'stream'


- function task:
	- returns void
	- params: stop_token, int numb
	- body:
		- get this thread's id
		- sync_out() - "call task(" << num << ")\n";

		// register a first callback
		- instantiate a stop_callback:
			- pass in the stop_token
			- pass in a lambda:
				- captures the num, id by value
				- body:
					- sync_out() << "- STOP1 requested in task(" << num
					<< (id == std::this_thread::get_id() ? ")\n"
					: ") in main thread\n")

		- sleep the thread for 9 milliseconds

		// register a second callback
		- instantiate a stop callback
			- pass in a stop_token
			- pass in a lambda:
				- captures the num, id by value
				- body:
					- sync_out() << "- STOP2 requested in task(" << num
					<< (id == std::this_thread::get_id() ? ")\n"
					: ") in main thread\n")

		- sleep the thread for 2 milliseconds

void for_main:
	- instantiate a stop_source
	- instantiate a stop_token from the stop_source

	// register callback
	- a stop_callback that:
		- takes the stop_token
		- lambda with body:
			syncOut() << "- STOP requested in main()\n" << std::flush;

	- run an async with a lambda which captures the stop_token by value
		- lambda body iters 1 to 9 calling task with the stop_token, num

	- sleep the thread for 120ms
	- request the stop from the stop_source
*/
#include <thread>
#include <iostream>
#include <future>
#include <chrono>
#include <syncstream>

using namespace std::literals;

auto sync_out(std::ostream& ostream = std::cout)
{
	return std::osyncstream{ ostream };
}

void task(std::stop_token stop_token, int num)
{
	auto id = std::this_thread::get_id();
	sync_out() << "call task(" << num << ")\n";

	// register a first callback
	std::stop_callback stop_callback1{
		stop_token,
		[num, id]
		{
			sync_out() << "- STOP1 requested in task(" << num
				<< (id == std::this_thread::get_id() ? ")\n" : ") in main thread\n");
		}
	};

	std::this_thread::sleep_for(9ms);

	// register a second callback
	std::stop_callback stop_callback2{
		stop_token,
		[num, id]
		{
			sync_out() << "- STOP2 requested in task(" << num
				<< (id == std::this_thread::get_id() ? ")\n" : ") in main thread\n");
		}
	};

	std::this_thread::sleep_for(2ms);
}


void for_main()
{
	std::stop_source stop_source;
	std::stop_token stop_token{ stop_source.get_token() };

	// register callback
	std::stop_callback stop_callback{
		stop_token,
		[]{sync_out() << "- STOP requested in main()\n" << std::flush_emit; }
	};

	auto future = std::async(
		[stop_token]
		{
			for (int i{ 1 }; i < 9; ++i)
			{
				task(stop_token, i);
			}
		});

	std::this_thread::sleep_for(120ms);

	stop_source.request_stop();
}