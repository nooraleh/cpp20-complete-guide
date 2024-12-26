#pragma once
#include <iostream>
#include <format>

void for_main()
{
	constexpr const char* fmt1 = "{}\n";				// compile-time format string
	std::cout << std::format(fmt1, 42);
}