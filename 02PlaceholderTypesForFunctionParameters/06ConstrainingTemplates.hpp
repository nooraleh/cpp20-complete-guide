#pragma once
#include <concepts>
#include <print>
#include <string>
/*
template function foo:
	- constrain template T to be an integral
	- arg 1 - placeholder parameter
	- arg 2 - T
	- arg 3 - a placeholder parameter that is convertible to T

	-body:
		- print the args out
*/


template<std::integral T>
void foo(auto x, T y, std::convertible_to<T> auto z)
{
	std::println("x={}:type({}), y={}, z={}", x, typeid(x).name(), typeid(y).name(), typeid(z).name());
}


void for_main()
{
	foo(64, 65, 'c');
	//foo(64, 65, "c");
	foo<long, char>(64, 65, 'c');
}