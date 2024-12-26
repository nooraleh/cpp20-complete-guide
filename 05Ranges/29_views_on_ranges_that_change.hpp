#pragma once
#include <ranges>
#include <iostream>
#include <vector>
#include <list>

/*


*/

void print(std::ranges::input_range auto&& range)
{
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}


void for_main()
{
	std::vector vector{ 1, 2, 3, 4, 5 };
	std::list list{ 1, 2, 3, 4, 5 };

	auto over2 = [](auto value) { return value > 2; };

	auto over2_vector_view = vector | std::views::filter(over2);
	auto over2_list_view = list | std::views::filter(over2);

	std::cout << "containers and elements over 2:\n";
	print(vector);
	print(list);
	print(over2_vector_view);
	print(over2_list_view);

	// modify the underlying range
	vector.insert(vector.begin(), { 9, 0, -1 });
	list.insert(list.begin(), { 9, 0, -1 });

	std::cout << "containers and elements over 2 (after inserting 9, 0, -1 to underlying) \n";
	print(vector);
	print(list);
	print(over2_vector_view);
	print(over2_list_view);

	// copying MIGHT eliminate caching
	auto over2_vector_view2 = over2_vector_view;
	auto over2_list_view2 = over2_list_view;

	std::cout << "elements over 2 after copying the view: \n";
	print(over2_vector_view2);
	print(over2_list_view2);
}