#pragma once
#include <type_traits>

template<typename T>
T foo_identity(T a, std::type_identity_t<T> b)
{
	return a + b;
}


template<typename T>
T foo_narrowing(T a, T b)
{
	return a + b;
}


void for_main()
{
	double d{ 4.3 };
	int i{ 1 };

	//foo_narrowing(d, i); // error;
	foo_identity(d, i); // 

	foo_identity(i, d); // 
}