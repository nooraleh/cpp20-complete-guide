#pragma once
#include <ranges>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

/*
- print the vector
- use ranges sort on a pr value of span with the middle three elements from `vector`
- print the vector again
- print the last 3 elements of vector using a pr-value span and a span member function

*/

void print(std::ranges::input_range auto&& collection)
{
	for (const auto& element : collection)
	{
		std::cout << std::quoted(element) << ' ';
	}
	std::cout << '\n';
}

void for_main()
{
	std::vector<std::string> vector{ "New York", "Tokyo", "Rio", "Berlin", "Sydney" };
	print(vector);

	std::ranges::sort(std::span{vector}.subspan(1, 3));
	print(vector);

	print(std::span{ vector }.last(3));
}