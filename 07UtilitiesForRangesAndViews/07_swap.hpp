#pragma once
#include <iostream>
#include <ranges>

/*

struct Foo
	- define the default ctor
	- define a copy ctor
		- cout that this has been call
	- define the copy assign
		- cuot
	- void swap:
		- takes Foo by l-value reference
		- cout "efficient swap\n"

- free function swap
	- takes two Foos by l-value reference
	- invokes the member of lhs and passes in rhs

- for_main:
	- define two Foos a and b

	- std::cout << "--- std::swap()\n";
	- call std::swap on a and b
	- std::cout << "--- end of std::swap()\n";

	std::cout << "--- swap() after using std::swap\n";
	being std::swap into the current namespace with a using
	call swap on a, b
	std::cout << "--- end of swap() after using std::swap\n";

	std::cout << "--- std::ranges::swap()\n";
	- call std::ranges::swap
	std::cout << "end of --- std::ranges::swap()\n";
*/

struct Foo
{
public:
	Foo() = default;

	Foo(const Foo& foo)
	{
		std::cout << "COPY CTOR CALLED\n";
	}

	Foo& operator=(const Foo& foo)
	{
		std::cout << "COPY ASSIGNMENT CALLED\n";
		return *this;
	}

	void swap(Foo& rhs)
	{
		std::cout << "EFFICIENT SWAP\n";
	}
};

void swap(Foo& lhs, Foo& rhs)
{
	lhs.swap(rhs);
}

void for_main()
{
	Foo a, b;
	std::cout << "--- std::swap()\n";
	std::swap(a, b);
	std::cout << "--- end of std::swap()\n";

	std::cout << "--- swap() after using std::swap\n";
	using std::swap;
	swap(a, b);
	std::cout << "--- end of swap() after using std::swap\n";

	std::cout << "--- std::ranges::swap()\n";
	std::ranges::swap(a, b);
	std::cout << "end of --- std::ranges::swap()\n";
}