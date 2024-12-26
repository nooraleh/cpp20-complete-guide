#pragma once
#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>

void print(const std::ranges::range auto& collection)
{
	for (const auto& element : collection)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main()
{
	std::vector<int> collection{ 25, 42, 2, 0, 122, 5, 7 };

	print(collection);

	std::ranges::sort(collection);

	print(collection);
}