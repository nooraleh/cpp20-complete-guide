#pragma once
#include <vector>
#include <iostream>
#include <ranges>
#include <random>
//#include <algorithm>

std::vector<int> generate_arithmetic_sequence_vector(int inclusive_start, int exclusive_end)
{
	auto iota_view = std::ranges::views::iota(inclusive_start, exclusive_end);
	return {iota_view.begin(), iota_view.end()};
}


void shuffle(std::vector<int>& vector)
{
	std::random_device random_device{};
	std::mt19937 mersenne_twister_generator{ random_device() };
	std::shuffle(vector.begin(), vector.end(), mersenne_twister_generator);
}

void print(const std::ranges::range auto& range)
{
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main()
{
	auto collection = generate_arithmetic_sequence_vector(1, 11);

	shuffle(collection);

	print(collection);
	std::ranges::sort(collection | std::ranges::views::take(5));
	print(collection);
}