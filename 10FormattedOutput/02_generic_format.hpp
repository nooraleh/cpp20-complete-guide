#pragma once
#include <format>
#include <print>
#include <iostream>
#include <chrono>

//template<typename T>
//concept printable =  std::formattable<T> && requires(T t) { std::cout << t; };


void print(const auto& arg1, const auto& arg2)
{
	std::cout << std::format("args: {} and {}\n", arg1, arg2);
}

void for_main1()
{
	print(7.5, true);
	print("character:", '?');
	print(std::chrono::system_clock::now(), std::chrono::seconds{ 13 });
}

void for_main2()
{
	std::cout << std::format("{:7}", 42) << '\n';
	std::cout << std::format("{:7}", 42.0) << '\n';
	std::cout << std::format("{:7}|", 'x') << '\n';
	std::cout << std::format("{:7}", true) << '\n';
}

void for_main3()
{
	std::cout << std::format("{:-<7}", 42);
}

void for_main() { for_main3(); }