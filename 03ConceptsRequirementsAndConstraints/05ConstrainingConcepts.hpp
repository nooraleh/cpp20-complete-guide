#pragma once
#include <concepts>
#include <ranges>

// compiler error?
//template<std::ranges::sized_range T>
//concept is_integral_val_type = std::integral<std::ranges::range_value_t<T>>;


// correct implementation 
template<typename T>
concept is_integral_val_type = std::ranges::sized_range<T> && std::integral<std::ranges::range_value_t<T>>;