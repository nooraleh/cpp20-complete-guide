#pragma once
#include <utility>
#include <ranges>

template<typename COLLECTION>
concept supports_push_back = requires(COLLECTION collection, COLLECTION::value_type value)
{
	collection.push_back(value);
};

template<typename COLLECTION>
concept supports_push_back = requires(COLLECTION collection)
{
	collection.push_back(std::declval<typename COLLECTION::value_type&>());
};

template<typename COLLECTION>
concept supports_push_back = requires(COLLECTION collection)
{
	collection.push_back(std::declval<std::ranges::range_value_t<COLLECTION>>());
};