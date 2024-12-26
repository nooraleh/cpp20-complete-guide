#pragma once
#include <iostream>
#include <iterator>
#include <ranges>


void for_main1()
{
	std::istream_iterator<int> it( std::cin );
	std::istream_iterator<int> sentinel;

	for (; it != sentinel; ++it)
	{
		std::cout << "Read: " << *it << '\n';
	}

}

void for_main()
{
	for_main1();
}