#pragma once
#include <concepts>
#include <print>
#include <string>

template<typename T1, typename T2>
	requires requires(T1 t1, T2 t2)
{
	*t2;				// line (1)
	t2[0];				// line (2)
	t2->value();		// line (3)
	*t2 > t1;			// line (4)
	t2 == nullptr;		// line (5)
}
void foo() {}


template<typename T1, typename T2>
	requires requires {false; }&& requires(T1 t1, T2 t2)
{
	*t2;				// line (1): opreator* has to be supported for T2
	t2[0];				// line (2): operator[] has to be supported for `int` as index
	t2->value();		// line (3): calling a member function `value` without arguments is possible
	*t2 > t1;			// line (4): support comparison of the result of operator* with T1
	t2 == nullptr;		// line (5): support the comparison of a T2 with a nullptr
}
void foo() {}


//template<typename T1, typename T2>
//	requires requires(T1 val, T2 p)
//{
//	*p > val || p == nullptr; // line (1)
//}
//void bar() {}

template<typename T1, typename T2>
requires
	requires(T1 val, T2 p)
	{
		*p > val;
	}
	|| requires(T1 val, T2 p)
	{
		p == nullptr;
	}
void bar(T1 val, T2 p) {}



// constrained template function line (1)
template<typename T>
requires std::integral<T>
void baz1()
{
	std::println("Constrains on std::integral");
}

// constrained template function (2)
template<typename T>
	requires requires { std::integral<T>; }
void baz2()
{
	std::println("Smelly code smell");
}


template<typename T>
concept standard_hashable = requires {std::hash<T>{}; };

void for_main()
{
	baz1<int>();
	//baz1<std::string>(); // ERROR

	baz2<int>();
	baz2<std::string>();
}