#pragma once
#include <concepts>
#include <print>

template<typename T1, typename T2>
requires std::same_as<T1, T2>
void foo(T1 t1, T2 t2)
{
	std::println("subset concept-constrained template function");
}


template<typename T1, typename T2>
	requires std::same_as<T2, T1> && std::integral<T1>
void foo(T1 t1, T2 t2)
{
	std::println("subsumption - std::same_as is commutative");
}


void for_main()
{
	foo(1, 2);
}