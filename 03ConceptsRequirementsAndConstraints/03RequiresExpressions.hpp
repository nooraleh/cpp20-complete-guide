#pragma once
#include <concepts>

template<typename T>
concept is_pointer = requires(T p)
{
	*p;									// operator * is valid
	p == nullptr;						// can compare with nullptr NOTE: this is not saying "equal to nullptr"
	{ p < p } -> std::same_as<bool>;	// operator< returns a bool
};

