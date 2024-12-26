#pragma once
#include <iostream>
#include <format>
#include <vector>
#include <ranges>

void for_main()
{
	std::vector<int> collection{ 8, 15, 7, 0, 9 };

	auto view = collection
		| std::views::transform([](auto element)
			{
				std::cout << std::format(" transform {}\n", element);
				return -element;
			})
		| std::views::filter([](auto element)
			{
				std::cout << std::format(" filter {}\n", element);
				return element % 3 == 0;
			});

	std::cout << "*** collection | filter | transform: *** \n";
	for (const auto& element : view)
	{
		std::cout << std::format("element: {}\n\n", element);
	}
}