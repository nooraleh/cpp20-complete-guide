#pragma once
#include <concepts>
#include <print>
#include <map>
#include <vector>

template<typename T>
	requires requires(T x, T y) { x + y; }
[[nodiscard]] T add(T x, T y)
{
	return x + y;
}

template<typename COLLECTION>
	requires requires {
		typename COLLECTION::value_type::first_type;
		typename COLLECTION::value_type::second_type;
}
void print(const COLLECTION& collection)
{
	for (const auto& [first, second] : collection)
	{
		std::println("({}, {})", first, second);
	}
}

void for_main1()
{
	auto result = add(3, 4);
	std::println("result: {}", result);
}

void for_main2()
{
	std::map m1 = { std::pair{"foo", 2}, {"bar", 3} }; // guide #2
	print(m1);

	//std::vector v1 = { 1,2,3,4,5 };
	//print(v1);
}

void for_main()
{
	for_main2();
}