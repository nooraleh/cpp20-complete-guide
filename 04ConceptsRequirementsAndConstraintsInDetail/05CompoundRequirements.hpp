#pragma once
#include <concepts>
#include <type_traits>
#include <print>

template<typename T>
concept unref_integral = std::integral<std::remove_reference_t<T>>;

template<typename T>
concept check = requires(T p)
{
	{ *p }->unref_integral;
};


void testy_test(check auto i)
{
	std::println("*i: {}", *i);
}


void for_main()
{
	int x{ 2 };
	int* px{ &x };

	testy_test(px);
}