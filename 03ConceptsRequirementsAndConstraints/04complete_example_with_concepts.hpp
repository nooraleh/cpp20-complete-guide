#pragma once
#include <concepts>
#include <print>
/*

write a concept 'is_pointer' which requires the following expressions:
	- deference operator is valid
	- can be compared with nullptr
	- comparing with < results is a type which is the same as bool


func max_value:
	- abbreviated function template
	- returns auto
	- takes auto a, auto b
	- body: no need to say more

func max_value:
	- constraints is_pointer on a and b
	- returns auto
	- requires that the type of what is dereferences has a total order with each other

void for_main:
	- int x 42
	- int y 77
	- print max_value on x, y and then addresses of x, y

	- address of x
	- address of y

	- print max_value of the address of the address of x, y

	- double d 49.9
	- print max_value on address of x, address of d
*/

template<typename T>
concept is_pointer = requires(T p)
{
	*p;
	p == nullptr;
	{ p < p } -> std::same_as<bool>;
};


auto max_value(auto a, auto b)
{
	return a < b ? b : a;
}


auto max_value(is_pointer auto a, is_pointer auto b)
	requires (std::totally_ordered_with<decltype(*a), decltype(*b)>)
{
	return max_value(*a, *b);
}


void for_main()
{
	int x{ 42 };
	int y{ 77 };

	std::println("max_value(x, y): {}", max_value(x, y));
	std::println("max_value(&x, &y): {}", max_value(&x, &y));

	int* px = &x;
	int* py = &y;

	std::println("max_value(&px, &py): {}", max_value(&px, &py));

	double d{ 49.9 };
	std::println("max_value(&x, &d): {}", max_value(&x, &d));
}