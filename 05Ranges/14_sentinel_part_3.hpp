#pragma once
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>

/*
Make a generic NTTPSentinel
	- define operator== in a generic way

	BONUS: Constrain on the type of the 'End' NTTP to match the type of the 'pos'
		when deferenced

for_main:
	- vector of {42, 8, 0, 15, 7, -1};
	- define a subrange with the begin of the vector and an NTTPSentinel of 7

	- sort the subrange

	- ranegs::for_each on the subrange, cout each

	-- do a custom for_each with an r-value reference instance of NTTPSentinel with NTTP value of -1
*/

template<auto SENTINAL_VALUE>
struct NTTPSentinel
{
public:
	bool operator==(auto pos) const
	{
		return *pos == SENTINAL_VALUE;
	}
};

void for_main1()
{
	/*
	0 8 15 42
	0 8 15 42 7
	*/
	std::vector<int> collection = { 42, 8, 0, 15, 7, -1 };

	std::ranges::subrange collection_subrange{ collection.begin(),NTTPSentinel<7>{} };

	std::ranges::sort(collection_subrange);

	std::ranges::for_each(collection_subrange, [](int arg) {std::cout << arg << ' '; });
	std::cout << '\n';

	std::ranges::for_each(collection.begin(), NTTPSentinel<-1>{}, [](int arg) {std::cout << arg << ' '; });
	std::cout << '\n';
}

void for_main2()
{
	std::string my_string{ "123abc MM" };

	std::ranges::subrange my_string_subrange{ my_string.begin() , NTTPSentinel <'M'>()};

	for(auto elemen : my_string_subrange)
	{
		std::cout << elemen << '-';
	}
	std::cout << '\n';
}

void for_main()
{

	for_main2();
}