#pragma once
#include <concepts>
#include <type_traits>
#include <iostream>


template<typename T>
void ensure_readonly_element_access(const T& collection)
	requires std::is_const_v<std::remove_reference_t<decltype(*collection.begin())>>
{}

void for_main()
{}