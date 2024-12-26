#pragma once
#include <concepts>
#include <iostream>

/*
-template function foo
	- takes typename T, typename U
	- requires T and U to be the same type
	- doesn't specify param names but takes T and U by value
	- body: helpful cout message

-template function foo
	- takes typename T, typename U
	- requires T and U to be the same type and that the integral type trait is true
	- doesn't specify param names but takes T and U by value
	- body: helpful cout message

void for main:
	call foo with integer literals 1 and 2

*/

template<typename T1, typename T2>
requires std::same_as<T1, T2>
void foo(T1, T2)
{
	std::cout << "both params are of the same type\n";
}

template<typename T1, typename T2>
requires std::same_as<T1, T2> && std::integral<T1>
void foo(T1, T2)
{
	std::cout << "both params are of the same type and are integral\n";
}

void for_main()
{
	foo(1, 2);
}
