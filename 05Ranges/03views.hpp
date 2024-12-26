#pragma once
#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>
#include <string>
#include <format>

void for_main()
{
	std::vector<std::string> collection{
		"Rio", "Tokyo", "New York", "Berlin",
		"London", "Los Angeles", "Manny On The Map"};

	for (const auto& element : collection | std::views::take(3))
	{
		std::cout << element << ", ";
	}
	std::cout << '\n';
}