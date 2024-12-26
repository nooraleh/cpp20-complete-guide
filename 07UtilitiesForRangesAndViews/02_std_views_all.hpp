#pragma once
#include <vector>
#include <ranges>
#include <iostream>
#include <vector>

void print(std::ranges::input_range auto collection)
{
	for (const auto& element : collection)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

void foo(std::ranges::view auto view)
{
	std::cout << "void foo(std::ranges::view auto view): ";
	for (const auto& element : view)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}


void for_main1()
{
	std::vector<std::string> collection{};

	print(collection);
	print(collection | std::views::all);
}

void for_main2()
{
	std::vector<std::string> collection{"test1", "test2", "test3"};

	foo(collection | std::views::all);

}

void for_main()
{
	for_main2();
}