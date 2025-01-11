module _02_consteval:_02_06_returning_a_collection_at_compile_time;

import std;

/*
template function 'merge_values':
	- template input_range T
	- specifier: consteval
	- returns: auto
	- params: T 'rg', variadic auto 'vals'
	body:
		// create compile-time vector from passed range:
		- deduce vector's element type with 'range_value_t' and use the std::vector ctor
			that expects a begin and end

		- use a fold expression with 'v.push_back' on the values
		
		- ranges::sort the vector

		// return extended collection as array:
		- constexpr auto 'sz' which is the size of the original rg and the sizeof the values

		- default initialize the 'arr' with the range_value_t (TODO: use a using), sz
		- ranges copy from source v into arr.begin
		- return arr
*/

template<std::ranges::input_range T>
consteval auto merge_values(T rg, auto... vals)
{
	using elem_T = std::ranges::range_value_t<T>;
	
	// create compile-time vector from passed range
	std::vector<elem_T> v{ std::ranges::begin(rg), std::ranges::end(rg) };

	(... , v.push_back(vals));

	std::ranges::sort(v);

	// return extended collection as array:
	constexpr auto sz = std::ranges::size(rg) + sizeof...(vals);

	std::array<elem_T, sz> arr;
	std::ranges::copy(v, arr.begin());
	return arr;
}


void for_main_partition()
{
	constexpr std::array orig{ 0, 8, 15, 132, 4, 77, 3 };
	auto merged = merge_values(orig, 42, 4);

	for (const auto& i : merged)
	{
		std::print("{} ", i);
	}
}