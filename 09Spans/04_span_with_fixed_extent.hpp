#pragma once
#include <span>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

/*
create a print_span function
	- template parameter T, NTTP Sz
	- body:
		- standard for each with newline at end

for_main:
	-std::vector<std::string> vec{"New York", "Tokyo", "Rio", "Berlin", "Sydney"};

	- define a span of a const string using the construct of vector.data, and the first 3
	- cout "first 3"
	- pass sp to print_span

	// sort elementes in the references vector
	- ranges sort the vector
	- cout first 3 after sort
	- pass sp to print_span

	// insert a new element
	// - must reassign the internal array of the vector if it reallocated new memory
	- get the old capacity
	- push back Cairo
	- check if the old and current cpacity are different
		- then reassign data and the first 3 to span
	- cour first 3 after push_back
	- pass sp to print_span

	// let span refer to the vector as a whole
	- assign vec to sp
	- cout "all"
	- pass sp to print_span

	// let span refer to the last five elements
	- sp = std::span{vector}.last(5)

	- pass to sp

	- assign last 4
	- print_span
*/

template<typename T, auto Sz>
void print_span(std::span<T, Sz> span)
	requires requires(T t) { std::cout << t; }
{
	for (const auto& element : span)
	{
		std::cout << std::quoted(element) << ' ';
	}
	std::cout << '\n';
}


void for_main()
{
	std::vector<std::string> vector{ "New York", "Tokyo", "Rio", "Berlin", "Sydney" };

	// span with a fixed extent
	std::span<const std::string, 3> sp{ vector.data(), 3 };
	std::cout << "first three: ";
	print_span(sp);

	std::ranges::sort(vector);
	std::cout << "first 3 after sort: ";
	print_span(sp);

	// insert a new element
	auto old_capacity = vector.capacity();
	vector.push_back("Cairo");
	if (old_capacity != vector.capacity())
	{
		sp = std::span < const std::string, 3>{ vector.data(), 3 };
	}
	std::cout << "first 3 after push_back: ";

	// last three elements
	sp = std::span<const std::string, 3>{ vector.end()-3, vector.end()};
	std::cout << "last three elements: ";
	print_span(sp);

	// last three elements - alternative
	sp = std::span{ vector }.last<3>();
	std::cout << "last three elements: ";
	print_span(sp);
}