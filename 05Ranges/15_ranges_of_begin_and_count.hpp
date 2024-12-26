#pragma once
#include <iostream>
#include <ranges>
#include <vector>

void for_main()
{
	auto iota_view = std::ranges::views::iota(1, 10);
	std::vector<int> collection{iota_view.begin(), iota_view.end()};

	if (
		auto pos5 = std::ranges::find(collection, 5);
		std::ranges::distance(pos5, collection.end()) >= 3
	)
	{
		for (int val : std::views::counted(pos5, 3))
		{
			std::cout << val << ' ';
		}
	}
}