#pragma once
#include <vector>
#include <ranges>
#include <iostream>
#include <string>


void for_main()
{
	std::vector<std::string> collection{ "just", "some", "strings", "to", "deal", "with" };
	std::vector<std::string> collection2{ "just", "some", "strings", "to", "deal", "with" };

	auto v1 = std::views::take(collection, 4);

	auto v2 = std::views::take(std::move(collection2), 4);

	auto v3 = v1 | std::views::take(2);
}