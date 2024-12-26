#pragma once
#include <iostream>
#include <ranges>
#include <vector>


std::vector<int> get_collection()
{
	auto iota_view = std::views::iota( 1, 20 );
	return { iota_view.begin(), iota_view.end()};
}

void for_main1()
{
	// fatal runtime error to use a reference to a temporary
	// as a collection in a ranged-based for loop
	for (auto i : std::vector<int>{1, 2, 3, 4})
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

void for_main2()
{
	for (auto i : get_collection() | std::views::take(5) | std::views::drop(2))
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}


void for_main()
{
	for_main1();
}