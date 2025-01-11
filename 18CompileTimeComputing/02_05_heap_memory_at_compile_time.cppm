module _02_consteval:_02_05_heap_memory_at_compile_time;

import std;

/*
template function 'modified_avg':
	- constrain with std::ranges::input_range
	- return: constexpr auto (TODO: try consteval as well)
	- params: const T& rg
	body:
		- type alias for the 'elem_T' using range_value_t
		
		// initialize compile-time vector with passed elements:
		- initialize a vector 'v' with the ranges::begin|end constructor
		
		// perform several modifications:
		-  push back a default initialization of the elem_T
		- ranges::sort 'v'
		- auto initialize a variable 'new_end' with std::unique 

		// return average of modified vector:
		- auto 'sum' std::accumulate:
			- v.begin
			- new_end
			- zero initialized elem_T


		- return sum over the static_cast to double of v.size()
		// TODO: Surely you want the distance between v.egin(), new_end instance of v.size()
*/

template<std::ranges::input_range T>
consteval auto modified_avg(T rg)
{
	using elem_T = std::ranges::range_value_t<T>;

	// initialize compile-time vector with passed elements
	std::vector<elem_T> v{ std::ranges::begin(rg), std::ranges::end(rg) };

	// perform several modifications
	v.push_back(elem_T{});
	std::ranges::sort(v);
	auto new_end = std::unique(v.begin(), v.end());

	// return average of modified vector
	auto sum = std::accumulate(v.begin(), new_end, elem_T{});

	return sum / static_cast<double>(v.size());
}

void fmp1_0205()
{
	constexpr std::array orig{ 0, 8, 15, 132, 4, 77 };
	//constexpr auto avg = modified_avg(orig);
	std::println("average: {}", modified_avg(orig));
}

constexpr auto return_vector()
{
	std::vector<int> v{ 0, 8, 15 };
	v.push_back(42);
	return v;
}

constexpr auto return_vector_size()
{
	auto coll = return_vector();
	return coll.size();
}

static void for_main_partition()
{
	constexpr auto tmp = return_vector_size();
}