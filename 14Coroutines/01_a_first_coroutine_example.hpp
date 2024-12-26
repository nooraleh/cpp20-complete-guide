#pragma once
#include <iostream>
#include "02_corotask.hpp"

CoroTask coro(int max)
{
	/*
	we want to program this as a coroutine that is suspended each
	time the print statement inside the loop is performed.

	Therefore, the function is interrupted and the user of the coroutine can
	trigger the next output with a resumption.
	*/

	std::cout << "CORO " << max << " start\n";

	for (int val{ 1 }; val <= max; ++val)
	{
		std::cout << "CORO " << val << '/' << max << '\n';

		co_await std::suspend_always{};
	}
	std::cout << "CORO " << max << " end\n";
}


void for_main()
{
	auto coro_task = coro(3);
	std::cout << "coro() started\n";

	while (coro_task.resume())
	{
		std::cout << "coro() suspended\n";
	}

	std::cout << "coro() done\n";
}