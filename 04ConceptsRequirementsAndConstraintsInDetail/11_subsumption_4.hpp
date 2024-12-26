#pragma once

/*
define a concept 'swappable_range'
	- input range and swappable

define a concept - contiguous_copyable
	- ranges continiguous and copyable

- define two corresponding foo functions that constraint on the respective
	concepts

for main:
	- call foo with a uniform-initialized vector of ints
*/

#include <ranges>
#include <concepts>
#include <vector>
#include <print>

template<typename T>
concept swappable_range = std::ranges::input_range<T> && std::swappable<T>;

//template<typename T>
//concept contiguous_range = std::ranges::contiguous_range<T> && std::copyable<T>;

template<typename T>
concept contiguous_range = std::ranges::contiguous_range<T> && std::copyable<T>;


void foo(swappable_range auto container)
{
	std::println("swappable_range auto container");
}

template<contiguous_range T>
void foo(T container)
{
	if constexpr (std::copyable<T>)
	{
		std::println("contiguous_range auto container");
	}
}


void for_main()
{
	foo(std::vector<int>{});
}