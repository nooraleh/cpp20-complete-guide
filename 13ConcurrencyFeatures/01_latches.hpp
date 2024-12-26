#pragma once
#include <iostream>
#include <thread>
#include <array>
#include <latch>
#include <chrono>
#include <print>

using namespace std::literals;

/*
function loop_over:
	- returns void
	- takes a char c
	- body:
		for j = 0; j < c/2; ++k
			- put 'c' to cout and then flush (all in one method chain)
			- sleep the thread for 100ms

void for_main:
	- std::array tags{'.', '?', '8', '+', '-'};  (CTAD should be fine)

	// initialize latch to react when all tasks are done:
	- instantiate a 'tags_processed_latch' with counter the ssize of 'tags'

	// start two threads dealing with every second tag:
	- one thread loops over 0 and +=2

	- the other loops over 1 and +=2
		pass the i'th tag to loop_over in both cases
		- call countdown on the latch


	- println("\nwaiting until all tasks are done")
	- call wait on the latch so main thread doesn't proceed until we are all counted down
	- println("\nall tasks done")
*/

void loop_over(char c)
{
	for (char j{ 0 }; j < c / 2; ++j)
	{
		std::cout.put(c).flush();
		std::this_thread::sleep_for(100ms);
	}
}


void for_main()
{
	std::array tags{ '.', '?', '8', '+', '-' };

	// initialize latch to react when all tasks are done:
	std::latch tags_processed_latch{ std::ssize(tags) };

	// start two threads dealing with every second tag:
	std::jthread jt0{
		[&tags, &tags_processed_latch]()
		{
			for (std::size_t i = 0; i < tags.size(); i += 2)
			{
				loop_over(tags[i]);
				tags_processed_latch.count_down();
			}
		}
	};

	std::jthread jt1{
		[&tags, &tags_processed_latch]()
		{
			for (std::size_t i = 1; i < tags.size(); i += 2)
			{
				loop_over(tags[i]);
				tags_processed_latch.count_down();
			}
		}
	};

	std::println("\nwaiting until all tasks are done");
	tags_processed_latch.wait();
	std::println("\nall tasks done");
}