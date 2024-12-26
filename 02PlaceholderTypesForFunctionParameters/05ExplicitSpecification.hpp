#pragma once
#include <print>
#include <string>

void print_func1(const auto& arg)
{
	// abbreviated function template
	std::println("print_func1: {}", arg);
}

auto print_func2 = [](const auto& arg)
	{
		// generic lamda
		std::println("print_func2: {}", arg);
	};


void for_main()
{
	print_func1<std::string>("hello");
	print_func2.operator()<std::string>("Hello");
}