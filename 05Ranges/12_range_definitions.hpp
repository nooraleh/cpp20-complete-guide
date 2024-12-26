#pragma once
#include <iostream>
#include <concepts>
#include <ranges>
#include <algorithm>

void print(const std::ranges::range auto& range)
{
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}

void for_main1()
{
	int raw_array[] = { 8, 6, 42, 1, 77 };
	print(raw_array);

	std::ranges::sort(raw_array);
	print(raw_array);
}


void for_main()
{
	for_main1();
}