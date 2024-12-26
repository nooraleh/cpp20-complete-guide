#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <concepts>

void for_main1()
{
	std::deque<int> deque = { 1, 2, 3, 4, 5 };
	std::vector<int> vector = { 1, 2, 3, 4, 5 };


	static_assert(std::random_access_iterator<decltype(deque.begin())>);

	static_assert(std::random_access_iterator<decltype(vector.begin())>);
	static_assert(std::contiguous_iterator<decltype(vector.begin())>);
}


void for_main()
{
	std::vector vector{ 1, 2, 3, 4 };
	auto pos = vector.begin();

	decltype(pos)::iterator_category; 
	decltype(pos)::iterator_concept; 

	// below asserts compile
	static_assert(std::same_as<decltype(pos)::iterator_category,std::random_access_iterator_tag>);
	static_assert(std::same_as<decltype(pos)::iterator_concept, std::contiguous_iterator_tag>);
}