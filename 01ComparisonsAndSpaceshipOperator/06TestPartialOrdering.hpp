#pragma once
#include <print>

void for_main()
{
	double a{ 1.0 };
	double b{ 2.0 };

	double nan{ NAN };

	std::println("(a <=> b) < 0: {}", (a <=> b) < 0);
	std::println("(a <=> b) == 0: {}", (a <=> b) == 0);
	std::println("(a <=> b) > 0): {}", (a <=> b) > 0);

	std::println("(a <=> nan) < 0: {}", (a <=> nan) < 0);
	std::println("(a <=> nan) == 0: {}", (a <=> nan) == 0);
	std::println("(a <=> nan) > 0: {}", (a <=> nan) > 0);
}