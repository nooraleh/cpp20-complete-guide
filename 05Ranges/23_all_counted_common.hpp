#pragma once
#include <ranges>
#include <iostream>
#include <algorithm>
#include <vector>

void print(std::ranges::input_range auto range, const std::string_view comment)
{
	std::cout << comment;
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main1()
{
	// std::views::all should be used to ensure that a container or range
	// is treated as a view to compose with other range-based utilities.
	/*auto iota_view = std::views::iota(1, 6);
	std::vector<int> numbers{ iota_view.begin(), iota_view.end() };*/

	int numbers[] = { 1, 2, 3, 4, 5 };
	auto numbers_all = std::views::all(numbers);

	for (int x : numbers | std::views::transform([](auto element) {return element * 2; }))
	{
		std::cout << x << ' ';
	}
	std::cout << '\b';
}

void for_main2()
{
	// std::views::counted is a range factory that creates a view starting from a pointer
	// or iterator and spanning a fixed number of elements

	// used when you want to create a range from a subset of a larger range
	int arr[] = { 10, 20, 30, 40, 50 };
	//auto view = std::views::counted(arr, 3);

	auto view = std::views::counted(std::ranges::begin(arr)+1, 3);

	print(view, "std::views::counted: ");

}

void for_main3()
{
	// std::views::common used for compatibility with legacy algorithms that
	// requires a .begin() and .end() iterator to be of the same type
	std::vector<int> numbers = { 10, 20, 30, 40, 50 };
	//auto view = std::ranges::views::counted(numbers.begin(), 3) | std::ranges::views::common;
	auto view = std::ranges::views::counted(numbers.begin(), 3);

	auto it = std::find(view.begin(), view.end(), 20);

	if (it != view.end())
	{
		std::cout << *it;
	}
}

void for_main()
{
	for_main3();
}