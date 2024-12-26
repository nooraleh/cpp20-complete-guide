#pragma once
#include <iostream>
#include <format>

void for_main()
{
	std::string str{ "hello" };
	std::cout << std::format("String '{}' has {} chars\n", str, str.size());

	std::cout << std::format("{1} is the size of string {0}\n", str, str.size());
}