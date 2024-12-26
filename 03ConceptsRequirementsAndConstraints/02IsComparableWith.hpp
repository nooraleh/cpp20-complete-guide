#pragma once
#include <concepts>
#include <print>

template<typename T1, typename T2>
concept is_comparable_with = requires(T1 t1, T2 t2) { t1 <=> t2; };

template<typename T>
concept is_pointer = std::is_pointer_v<T>;

template<typename T>
concept is_not_pointer = !std::is_pointer_v<T>;

auto max_value(is_not_pointer auto a, is_not_pointer auto b)
requires std::totally_ordered_with<decltype(a), decltype(b)>
{
	return a > b ? a : b;
}


auto max_value(is_pointer auto a, is_pointer auto b)
requires std::totally_ordered_with<decltype(*a), decltype(*b)>
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