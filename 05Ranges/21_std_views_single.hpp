#pragma once
#include <iostream>
#include <ranges>
#include <string_view>

void print(std::ranges::input_range auto range, const std::string_view comment)
{
	std::cout << comment;
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}


void for_main()
{
	// std::ranges::views::single is an abstract of a range containing exactly one object
	// allows for single values to still have access to range-based apis

	auto single_view = std::ranges::views::single(3);
	print(single_view, "single view: ");
}