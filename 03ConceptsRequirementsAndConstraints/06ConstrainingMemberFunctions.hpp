#pragma once
#include <iostream>
#include <ranges>
#include <vector>

/*
Define a class 'ValOrCall' - intended to store a value type or a collection type (e.g. std::vector)

- private:
	T m_value

- pbulic:
	- const  ref ctor
	- copy constructs m_value in the ctor init list

	- rvalue reference T ctor
	- moves param into the T data member

	- const-qualified print function

	- const-qualified print function
	- constrains on the requirement of T being a range
	- body: range-based for print out

*/

template<typename T>
concept coutable = requires(T t) { std::cout << t; };

template<typename T>
class ValOrColl
{
public:
	ValOrColl(const T& value)
		: m_value{value}
	{ }

	ValOrColl(T&& value)
		: m_value{std::move(value)}
	{ }

	void print() const
	{
		std::cout << m_value << '\n';
	}

	void print() const
	requires std::ranges::range<T>
	{
		for (const auto& element : m_value)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}

private:
	T m_value;
};

void for_main()
{
	ValOrColl o1{ 42 };
	o1.print();

	ValOrColl o2 = std::vector{ 1, 2, 3, 4, 5 };
	o2.print();
}