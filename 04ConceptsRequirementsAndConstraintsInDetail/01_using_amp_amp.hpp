#pragma once
#include <concepts>
#include <iterator>


template<typename T>
requires (sizeof(T) > 4) && requires {typename T::value_type; } && std::input_iterator<T>
void foo(T t)
{}


template<typename T>
requires std::integral<T> || std::floating_point<T>
T power(T a, T b)
{
	// implementation ...
}


template<typename T>
requires std::is_pointer_v<T> || std::same_as<T, std::nullptr_t>
void foo()
{ }