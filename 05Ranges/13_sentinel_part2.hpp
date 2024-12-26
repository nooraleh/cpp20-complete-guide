#pragma once
#include <iostream>
#include <ranges>
#include <algorithm>
/*

struct NullTerm

void for_main:
	- c-style string of "Hello world"
	- define a subrange with the c-style string and the an instance of NullTerm
	- use this new subrange in a ranges foreaach to print out each character
	- use a range-based for loop over the subrange
*/

struct NullTerm
{
public:
	bool operator==(auto pos) const
	{
		return *pos == '\0';
	}
};


void for_main1()
{
	const char* c_style_string = "Hello world";
	std::ranges::subrange c_style_string_subrange{ c_style_string , NullTerm {} };

	std::ranges::for_each(c_style_string_subrange, [](char c) {std::cout << c << ' '; });
	std::cout << '\n';

	for (const auto& c : c_style_string_subrange)
	{
		std::cout << c << ' ';
	}
	std::cout << '\n';
}

void for_main2()
{
	const char* c_style_string = "Hello world";
	for (const auto& element : std::ranges::subrange{ c_style_string , NullTerm{} })
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';

}

void for_main()
{
	for_main2();

}