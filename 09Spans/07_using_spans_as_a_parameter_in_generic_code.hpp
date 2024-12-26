#pragma once
#include <span>
#include <iostream>
#include <type_traits>
#include <vector>
#include <utility>

template<typename T, auto Sz>
void print_span(std::span<T, Sz> span)
	requires
	requires(T t) { std::cout << t; } && std::is_const_v<std::remove_reference_t<decltype(std::declval<T>())>>
{
	std::cout << "[" << span.size() << " elems";
	if constexpr (Sz == std::dynamic_extent)
	{
		std::cout << " (dynamic)";
	}
	else
	{
		std::cout << " (fixed)";
	}
	std::cout << ":";
	for (const auto& elem : span)
	{
		std::cout << elem << ' ';
	}
	std::cout << "]\n";
}

void for_main()
{
	std::vector vector{ 1, 2, 3, 4, 5 };

	print_span<const int, std::dynamic_extent>(vector);
	print_span<const int, std::dynamic_extent>(std::vector{ 1, 2, 3, 4, 5 });

	std::span<int, 5> spanFix{ vector.begin(), 5 }; // OK
	std::span<int, 5> spanFix2 { vector.begin(), 5 }; // ERROR
	//std::span<int, 0> test;
}