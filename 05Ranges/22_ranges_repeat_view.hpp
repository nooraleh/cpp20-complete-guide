#pragma once
#include <iostream>
#include <ranges>
#include <string_view>

// for 'sv' string_view suffix
using namespace std::literals;
/*

void for_main:
	- bounded overload
	- loop over the C++ string_view (use the literal suffix) 4 times
		- print with a space
	- endline

	- unbounded overload
	- loop over a view to repeat string view "I know that.."
		- cout with a space

	- endline

*/

void for_main()
{
	// bounded overload of std::views::repeat
	for (auto string : std::views::repeat("C++"sv, 4))
	{
		std::cout << string << ' ';
	}
	std::cout << '\n';

	for (auto string : std::views::repeat("I know that she knows that"sv)
						| std::views::take(3)
		)
	{
		std::cout << string << ' ';
	}
	std::cout << '\n';
}