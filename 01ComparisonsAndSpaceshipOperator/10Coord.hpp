#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <print>
#include <algorithm>

/*
Define a struct 'Coord' which has
	- three doubles default initialized 'x' y and x
	- default comparison operator defined

for_main:
	- define a vector of Coord
	- sort them 
	- ranged based for and print out the info post-sorting
*/

struct Coord
{
public:
	double x{};
	double y{};
	double z{};

	auto operator<=>(const Coord& coord) const = default;
};


std::ostream& operator<<(std::ostream& COUT, const Coord& coord)
{
	COUT << std::format("Coord(x={},y={},z={})", coord.x, coord.y, coord.z);
	return COUT;
}



void for_main()
{

	std::vector<Coord> coll{ {0, 5, 5}, {5, 0, 0}, {3, 5, 5}, {3, 0, 0}, {3, 5, 7} };

	std::println("------------- Before Sorting -------------");
	for (const auto& element : coll)
	{
		std::cout << element << '\n';
	}


	std::sort(coll.begin(), coll.end());
	std::println("------------- After Sorting  -------------");
	for (const auto& element : coll)
	{
		std::cout << element << '\n';
	}
}