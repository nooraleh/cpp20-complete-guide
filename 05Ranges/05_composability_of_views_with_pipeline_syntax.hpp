#pragma once
#include <map>
#include <ranges>
#include <string>
#include <iostream>


void for_main()
{
	// map of composers (name->year of birth)
	std::map<std::string, int> composers{
		{"Bach", 1685},
		{"Mozart", 1756},
		{"Beethoven", 1770},
		{"Tchaikovsky", 1840},
		{"Chopin", 1810},
		{"Vivaldi ", 1678},
	};

	for (const auto& composer : composers
		| std::ranges::views::filter([](auto element) {return element.second > 1700;})
		| std::ranges::views::take(3)
		| std::ranges::views::keys
	)
	{
		std::cout << composer << '\n';
	}
}