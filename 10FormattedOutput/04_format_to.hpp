#pragma once
#include <string>
#include <format>
#include <iostream>

void for_main1()
{
	std::string value1;
	std::format_to(std::back_inserter(value1), "test me: {}", 42);

	std::string value2{ std::format("test me: {}", 42) };

	std::cout << std::boolalpha << (value1 == value2) << '\n';
}

void for_main2()
{
	// writing to std::ostream_buf_iterator<char>{std::cout}
	std::string s{ "hello" };
	std::format_to(std::ostreambuf_iterator<char>{std::cout}, "string {} has {} chars", s, s.size());
}


void for_main3()
{
	std::string str{ "imagine the size of this is determined at runtime" };
	std::size_t threshold{ 100 };

	// if the size of the formatting output is above a certain amount...
	if (auto sz = std::formatted_size("String '{}' has '{}' chars", str, str.size()); sz > threshold)
	{
		// then logic
	}
	else
	{
		// else logic
	}
}

void for_main() { for_main2(); }