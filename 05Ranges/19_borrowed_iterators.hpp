#pragma once
#include <vector>
#include <algorithm>
#include <ranges>
#include <print>
#include <iostream>

std::vector<int> get_data()
{
	auto iota_view = std::ranges::iota_view{ 30, 50 };
	return { iota_view.begin(), iota_view.end() };
}

void for_main()
{
	auto&& data = get_data();
	auto pos = std::ranges::find(data, 42);
	std::println("*pos: {}", *pos);     // line (1)
	std::cout << *pos;					// line (2)
}