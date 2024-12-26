#pragma once
#include <concepts>
#include <print>
#include <cstdint>

template<typename T>
requires (std::convertible_to<T, int>)
void print()
{
	std::println("Less specialized: {}", sizeof(T));
}


template<typename T>
	requires (std::convertible_to<T, int> && sizeof(T) >= 4)
void print()
{
	std::println("Subsumption!! Baby!! {}", sizeof(T));
}


void for_main()
{
	print<short>();
	print<std::int8_t>();
	print<int>();
}