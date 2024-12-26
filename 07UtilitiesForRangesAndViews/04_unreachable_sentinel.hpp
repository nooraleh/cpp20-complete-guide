#pragma once
#include <ranges>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> get_data()
{
	// we know for a fact that 42 resides in this collection
	auto iota_view = std::views::iota(40, 50);
	return { iota_view.begin(), iota_view.end() };
}

void for_main()
{
	auto collection = get_data();

	//auto pos42 = std::ranges::find(collection, 42);
	auto pos42 = std::ranges::find(collection.begin(), std::unreachable_sentinel, 42);

	std::cout << *pos42 << '\n';
}