#pragma once
#include <concepts>
#include <iostream>
#include <vector>

template<typename COLLECTION>
concept push_backable = requires (COLLECTION collection, COLLECTION::value_type value) { collection.push_back(value); };

template<typename COLLECTION>
requires push_backable<COLLECTION>
void add(COLLECTION& collection, const typename COLLECTION::value_type& value)
{
	std::cout << "calls NON-floating point VERSION\n";
	collection.push_back(value);
}


template<typename COLLECTION>
	requires push_backable<COLLECTION> && std::floating_point<typename COLLECTION::value_type>
void add(COLLECTION& collection, const typename COLLECTION::value_type& value)
{
	// special code for floating-point values
	std::cout << "calls FLOATING POINT VERSION\n";
	collection.push_back(value);
}

void for_main()
{
	std::vector<int> int_vector;
	add(int_vector, 42);

	std::vector<double> double_vector;
	add(double_vector, 0.7);
}