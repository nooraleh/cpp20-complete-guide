#pragma once
#include <vector>
#include <concepts>

// overload 1
template<typename COLLECTION>
void add(COLLECTION& collection, const typename COLLECTION::value_type& value) // pass by const reference
{
	collection.push_back(value);
}


// overload 2
template<typename COLLECTION>
void add(COLLECTION& collection, typename COLLECTION::value_type value) // pass by value
	requires std::floating_point<typename COLLECTION::value_type>
{
	collection.push_back(value);
}


void for_main()
{
	std::vector<double> double_vector;	// COLLECTION::value_type is a floating point
	add(double_vector, 0.7);			// `0.7` is an r-value reference
}