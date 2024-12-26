#pragma once
#include <array>
#include <format>
#include <iostream>

template<auto SIZE>
void write_to_buffer(std::array<char, SIZE>& buffer, const auto& arg1, const auto& arg2)
{
	auto ret = std::format_to_n(buffer.begin(), buffer.size() - 1, "args: {} and {}", arg1, arg2);
	*(ret.out) = '\0';
}


void for_main()
{
	std::array<char, 64> buffer;
	write_to_buffer(buffer, "test1", "test2");
	std::cout << buffer.data() << '\n'; 
	// output: args: test1 and test2
}