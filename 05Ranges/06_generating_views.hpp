#pragma once
#include <ranges>
#include <iostream>
#include <vector>

void for_main1()
{
	//1 2 3 4 5 6 7 8 9 10
	for (int val : std::ranges::views::iota(1, 11))
	{
		std::cout << val << ' ';
	}
	std::cout << std::endl;
}


void for_main2()
{
	auto sequence_view = std::ranges::views::iota(1, 11);
	std::vector<int> vecky{ sequence_view.begin(), sequence_view.end() };
}


void for_main()
{
	for_main1();
}