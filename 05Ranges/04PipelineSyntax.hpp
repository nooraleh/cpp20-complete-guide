#pragma once
#include <vector>
#include <ranges>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <string_view>

std::vector<int> generate_arithmetic_sequence_vector(int start, std::size_t reserve_size)
{
	std::vector<int> return_vector(reserve_size);
	std::iota(return_vector.begin(), return_vector.end(), start);
	return return_vector;
}

void print(const auto& range, std::string_view comment)
{
	std::cout << comment << ": ";
	for (auto element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}


void for_main()
{
	auto collection = generate_arithmetic_sequence_vector(1, 13);

	auto custom_view = collection
		| std::views::filter([](auto element) {return element % 3 == 0; })
		| std::views::transform([](auto element) {return element * element; })
		| std::views::take(3);

	std::cout << "custom_view (with pipe syntax)" << ": ";
	for (auto element : custom_view)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}

void for_main1()
{
	auto collection = generate_arithmetic_sequence_vector(1, 13);


	// old-style syntax - hard to read, hard to maintain, hard to bloody make
	auto custom_view1 = std::views::take(
		std::views::transform(
			std::views::filter(collection,
				[](auto elem) { return elem % 3 == 0; }),
			[](auto elem) { return elem * elem; }),
		3);

	//print(custom_view1, "custom_view (without pipe syntax)");
	std::cout << "custom_view1 (with pipe syntax)" << ": ";
	for (auto element : custom_view1)
	{
		std::cout << element << ' ';
	}
	std::cout << std::endl;
}