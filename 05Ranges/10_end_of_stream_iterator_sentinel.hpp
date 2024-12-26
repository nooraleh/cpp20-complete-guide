#pragma once
#include <iostream>
#include <algorithm>

void for_main()
{
	std::for_each(
		std::istream_iterator<int>{std::cin},
		std::istream_iterator<int>{},
		[](auto value) {std::cout << value << '\n'; }
	);
}