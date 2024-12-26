#pragma once
#include <thread>
#include <ranges>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

void for_main()
{
	std::list<int> list = { 1, 2, 3, 4, 5 };

	const auto view = list | std::views::drop(2);

	//std::jthread print_thread{
	//	[&view, &list]()
	//	{
	//		for (const auto& element : view)
	//		{
	//			std::cout << element << '\n';
	//		}
	//	}
	//};

	//for (const auto& element : view)
	//{
	//	std::cout << element << '\n';
	//}
}