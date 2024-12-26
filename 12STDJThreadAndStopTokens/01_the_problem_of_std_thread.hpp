#pragma once
#include <thread>
#include <iostream>
#include <string>
#include <print>

void for_main()
{
	std::thread t1{ [](std::string name, int val) {std::println("{}, {}", name, val); }, "Noor", 28};

	t1.join();
} 