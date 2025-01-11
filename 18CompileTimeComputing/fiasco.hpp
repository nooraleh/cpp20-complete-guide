#pragma once
#include <iostream>
#include "truth.hpp"

int val{ the_truth.m_value };

void for_main()
{
	std::cout << val << '\n';
	val++;
	std::cout << val << '\n';
}