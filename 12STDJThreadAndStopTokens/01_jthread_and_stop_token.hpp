#pragma once
#include <print>
#include <thread>

void for_main()
{
	std::thread t1{
		[]
		{
			std::println("printing from new thread!");
		}
	};


	std::println("main: before joining!");
	//t1.join();
	std::println("main: after joining!");

	t1.detach();
}