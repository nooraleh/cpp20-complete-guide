#pragma once
#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>
#include <string>

void print(const std::ranges::range auto& collection)
{
	for (const auto& element : collection)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main()
{
	std::vector<std::string> coll{ "Rio", "Tokyo", "New York", "Berlin" };

	std::ranges::sort(coll);

	std::ranges::sort(coll); // sort elements
	std::ranges::sort(coll[0]); // sort character in first element
	print(coll);

	int arr[] = { 42, 0, 8, 15, 7 };
	std::ranges::sort(arr); // sort values in array
	print(arr);
}