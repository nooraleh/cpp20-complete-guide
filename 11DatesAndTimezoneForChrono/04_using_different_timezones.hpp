#pragma once
#include <chrono>
#include <print>

// example output: 2024-12-17 17:18:35
auto get_current_utc_datetime()
{
	return std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now());
}

void for_main()
{
	std::println("{}", get_current_utc_datetime());
}