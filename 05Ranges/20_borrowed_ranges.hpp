#pragma once
#include <vector>
#include <algorithm>
#include <ranges>
#include <iostream>

void for_main1()
{
	std::vector<int> collection{ 0, 8, 15 };

	// `pos8` exists in the scope of `collection`
	auto pos8 = std::ranges::find(collection, 8);
	std::cout << *pos8;
}


void for_main2()
{

}

void for_main()
{

}