#pragma once
#include <iostream>
#include <ranges>

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

void for_main()
{
	int arr[] = { 0, 8, 15, 42, 7 };
	auto odd = [](auto value) {return value % 2 != 0; };

	std::cout << "max odd value in `arr`: " << max_value(arr | std::views::filter(odd)) << '\n';
}