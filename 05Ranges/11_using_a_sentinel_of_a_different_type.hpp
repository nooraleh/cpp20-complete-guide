#pragma once
#include <iostream>
#include <algorithm>
#include <ranges>

// simply example of using a sentinel of a different type to iterate over a "range"
// where the types of the iterators differ

/*
struct NullTermFunctor
	- defines the == operator on auto any param
		- returns whether the deferences object can be compared with null character

void for_main:
	- const char* c string of hello world
	- for loop checking until we are not equal with an instance of NullTermFunctor
		- print out

	- do the above but in a range based for_each

BONUS TOOD: Add appropriate constraints on NullTermFunctor
*/

struct NullTermFunctor
{
public:
	bool operator==(auto param) const
		requires requires
	{
		*param;
		{ *param == '\0' } -> std::convertible_to<bool>;
	}
	{
		return *param == '\0';
	}
};


void for_main()
{
	const char* c_style_string = "Hello World";

	for (auto p = c_style_string; p != NullTermFunctor{}; ++p)
	{
		std::cout << *p << ' ';
	}
	std::cout << '\n';

	std::ranges::for_each(c_style_string, NullTermFunctor{}, [](char c) {std::cout << c << ' '; });
	std::cout << '\n';
}