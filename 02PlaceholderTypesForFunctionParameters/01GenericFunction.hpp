#pragma once
#include <iostream>


template<typename T>
concept coutable = requires(T t) { std::cout << t; };

template<typename T>
concept range_based_forable = requires(T t) { t.begin(); t.end(); };

template<typename T>
requires coutable<typename T::value_type> && range_based_forable<T>
void print_collection(coutable auto collection)
{
	foreach(const auto & element : collection)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}


