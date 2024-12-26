#pragma once
#include <iostream>


void print(auto val)
{
	std::cout << val << '\n';
}


void for_main()
{
	print(64);
	print<char>(64);
}


void foo()
{
	struct Data
	{
		void mem(auto param) {}
	};
}