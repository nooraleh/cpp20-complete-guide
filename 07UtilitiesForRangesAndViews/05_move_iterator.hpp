#pragma once
#include <ranges>
#include <vector>

std::vector<int> get_data()
{
	// we know for a fact that 42 resides in this collection
	auto iota_view = std::views::iota(40, 50);
	return { iota_view.begin(), iota_view.end() };
}

void for_main()
{
	auto collection = get_data();
	for (std::move_iterator pos{ collection.begin() }; pos != std::move_sentinel{ collection.end() }; ++pos)
	{
		std::size_t
	}
}