#pragma once
/*
for_main:
	- std::vector<int> collection{ 8, 15, 7, 0, 9 };
	- auto define a view with pipe syntax:
		- filter on being a multiple of 3, first cout "filter "
		- transform on negating the element, first cout " transform "

	- std::cout << "*** coll | filter | transform:\n";
	- ranged-based for on the collection and cout "val: {}"
*/
#include <iostream>
#include <format>
#include <vector>
#include <ranges>

void for_main()
{
	std::vector<int> collection{ 8, 15, 7, 0, 9 };

	auto view = collection
		| std::views::filter([](auto element)
			{
				std::cout << std::format(" filter {}\n", element);
				return element % 3 == 0;
			})
		| std::views::transform([](auto element)
			{
				std::cout << std::format(" transform {}\n", element);
				return -element;
			});

	std::cout << "*** collection | filter | transform: *** \n";
	for (const auto& element : view)
	{
		std::cout << std::format("element: {}\n\n", element);
	}

	std::cout << "*** ------------------------------ *** \n";
	for (const auto& element : view)
	{
		std::cout << std::format("element: {}\n\n", element);
	}

	std::cout << "*** ------------------------------ *** \n";
	for (const auto& element : view)
	{
		std::cout << std::format("element: {}\n\n", element);
	}
}