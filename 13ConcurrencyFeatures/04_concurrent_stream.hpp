#pragma once
#include <iostream>
#include <thread>
#include <cmath>
#include <syncstream>

void print_square_roots(int num)
{
	for (int i{ 0 }; i < num; ++i)
	{
		std::cout << "the square root of: " << i << " is " << std::sqrt(i) << '\n';
	}
}

auto sync_out(std::ostream& ostream = std::cout)
{
	return std::osyncstream{ ostream };
}

void print_square_roots(int num)
{
	for (int i{ 0 }; i < num; ++i)
	{
		sync_out() << "the square root of: " << i << " is " << std::sqrt(i) << '\n';
	}
}


void for_main()
{
	std::jthread jt0{ print_square_roots, 5 };
	std::jthread jt1{ print_square_roots, 5 };
	std::jthread jt2{ print_square_roots, 5 };
}