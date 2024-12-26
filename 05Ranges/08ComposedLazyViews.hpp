#pragma once
#include <iostream>
#include <ranges>

void for_main()
{
	/*
	generate a compose lazy view of:
		- iota from 1 with no end specified
		- filter on evenness
		- take the first 5

	- iterate over this sequence a view times
		- print out the elements
	*/

	auto composed_lazy_view = std::ranges::views::iota(1)
		| std::ranges::views::filter([](auto element) {return element % 2 == 0; })
		| std::ranges::views::take(5);

	//// prints '2 4 6 8 10' on a new line each time
	//for (int i{ 0 }; i < 4; ++i)
	//{
	//	for (auto element : composed_lazy_view)
	//	{
	//		std::cout << element << ' ';
	//	}
	//	std::cout << '\n';
	//}

	// prints '2 4 6 8 10' twice
	//for (auto element : composed_lazy_view)
	//{
	//	std::cout << element << ' ';
	//}
	//std::cout << '\n';

	//for (auto element : composed_lazy_view)
	//{
	//	std::cout << element << ' ';
	//}
	//std::cout << '\n';
}