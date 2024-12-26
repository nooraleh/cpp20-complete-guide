#pragma once
#include <ranges>
#include <iostream>
#include <random>
#include <string_view>

void shuffle(std::ranges::range auto& range)
{
	std::random_device random_device{};
	std::mt19937 mersenne_twister_generator{ random_device() };
	std::shuffle(range.begin(), range.end(), mersenne_twister_generator);
}

void print(const std::ranges::input_range auto& range, const std::string_view& comment)
{
	std::cout << comment;
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void for_main_qna()
{
	auto iota_view = std::ranges::views::iota(-10, 11);
	std::vector<int> vector{ iota_view.begin(), iota_view.end() };
	std::ranges::sort(vector, std::ranges::less{}, [](const auto& element) {return std::abs(element); });
}

void for_main1()
{
	auto iota_view = std::ranges::views::iota(-10, 11);
	std::vector<int> vector{ iota_view.begin(), iota_view.end() };

	print(vector, "pre-shuffling: ");
	shuffle(vector);
	print(vector, "post-shuffling, pre-sorting: ");

	std::ranges::sort(vector, [](const auto& lhs, const auto& rhs) {return std::abs(lhs) < std::abs(rhs); });
	print(vector, "post-sorting: ");
}

void for_main2()
{
	auto iota_view = std::ranges::views::iota(-10, 11);
	std::vector<int> vector{ iota_view.begin(), iota_view.end() };

	print(vector, "pre-shuffling: ");
	shuffle(vector);
	print(vector, "post-shuffling, pre-sorting: ");

	std::ranges::sort(vector, std::ranges::less{}, [](const auto& element) {return std::abs(element); });
	print(vector, "post-sorting: ");
}

void for_main()
{
	for_main2();
}