#pragma once
#include <vector>
#include <array>
#include <concepts>
#include <span>

void for_main()
{
	std::array array{ 1, 2, 3, 4, 5 };
	std::vector vector {1, 2, 3, 4, 5};

	std::span<int> array_span_dyn{ array };
	std::span<int> vector_span_dyn{ vector };

	static_assert(std::same_as<decltype(array_span_dyn), decltype(vector_span_dyn)>);
}