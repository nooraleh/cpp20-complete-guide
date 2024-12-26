#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <format>

using namespace std::literals;

void little_sleep(std::chrono::microseconds us)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + us;

	do
	{
		std::this_thread::yield();
	} while (std::chrono::high_resolution_clock::now() < end);

}

void for_main()
{
	auto start = std::chrono::high_resolution_clock::now();
	little_sleep(100us);
	auto elapsed = std::chrono::high_resolution_clock::now() - start;

	std::format_to(
		std::ostreambuf_iterator<char>{std::cout},
		"waited for {}us",
		std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
	);
}