#pragma once
#include <ranges>
#include <vector>
#include <iostream>

std::vector<int> get_data()
{
	// we know for a fact that 42 resides in this collection
	auto iota_view = std::views::iota(40, 50);
	return { iota_view.begin(), iota_view.end() };
}


void print(std::ranges::input_range auto&& range)
{
	for (auto pos = std::ranges::begin(range); pos != std::ranges::end(range); std::ranges::advance(pos, 2, std::ranges::end(range)))
	{
		std::cout << *pos << ' ';
	}
	std::cout << '\n';
}


void for_main()
{
	auto collection = get_data();

	print(collection);


}