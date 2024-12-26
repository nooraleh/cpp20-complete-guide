#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

void for_main()
{
	auto iota_view = std::views::iota(1, 11);
	std::vector<int> collection{ iota_view.begin(), iota_view.end() };

	collection | std::views::transform(
		[](const auto& value) // better to use const auto&
		{
			//++value; //  modification now a compiler error
			return value;
		}
	);
}