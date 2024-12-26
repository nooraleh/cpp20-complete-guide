#pragma once
#include <concepts>
#include <print>
#include <utility>

template<typename T>
concept is_pointer = std::is_pointer_v<T>;

template<typename T>
requires(!is_pointer<T>)
T max_value(T a, T b)
{
	return a < b ? b : a;
}

template<typename T>
requires(is_pointer<T>)
auto max_value(T a, T b)
{
	return max_value(*a, *b);
}


void for_main()
{
	int x{ 42 }, y{ 77 };
	int* px{ &x };
	int* py{ &y };
	int** ppx{ &px };
	int** ppy{ &py };


	std::println("max_value(x, y): {}", max_value(x, y));
	std::println("max_value(&x, &y): {}", max_value(&x, &y));
	std::println("max_value(ppx, ppy): {}", max_value(ppx, ppy));
}