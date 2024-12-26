#pragma once
#include <ranges>
#include <print>
#include <iostream>
/*

max_value_function:
	- const ref to auto with constraint on being an input_range
	- returns the range_value of the range
	body:
		- if the range is empty (use the <range> header's free function
			- return the default initialized value of the range_value

		- take the free function being of the range
		- dererence and set to max
		- while we're incrementing the being pos and it is not the end of the range
			- if the dereference of the position is greater than max
				- assign to max
		- return max
*/
template<std::ranges::input_range RANGE>
std::ranges::range_value_t<RANGE> max_value(RANGE&& range)
{
	if (std::ranges::empty(range))
	{
		return std::ranges::range_value_t<RANGE>{};
	}

	auto pos = std::ranges::begin(range);
	auto max = *pos;

	while (++pos != std::ranges::end(range))
	{
		if (*pos > max)
		{
			max = *pos;
		}
	}
	return max;
}

void print(std::ranges::input_range auto range, const std::string_view comment)
{
	std::cout << comment;
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main()
{
	int c_style_array[] = { 44, 22, 40, 1, 50, 85, 23 };
	auto subrange = std::ranges::subrange{ c_style_array };
	print(subrange, "c_style_array");
	std::println("max: {}", max_value(subrange));
}