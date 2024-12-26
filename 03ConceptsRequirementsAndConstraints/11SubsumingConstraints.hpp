#pragma once
#include <concepts>

template<typename FROM, typename TO>
concept ConvertsWithoutNarrowing = std::convertible_to<FROM, TO> &&
	requires(FROM&& x)
{
	{
		std::type_identity_t<TO[]>{std::forward<FROM>(x)}
	} -> std::same_as<TO[1]>;
};



template<typename From, typename To>
concept ConvertsWithoutNarrowing =
std::convertible_to<From, To>&&
	requires (From&& x) {
		{ std::type_identity_t<To[]>{std::forward<From>(x)} } -> std::same_as<To[1]>;
};