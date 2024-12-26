#pragma once
#include <format>
#include <iostream>


class Always40
{
public:
	int get_value() const { return 40; }
};


template<>
struct std::formatter<Always40>
{
	// parse the format string for this type
	constexpr auto parse(std::format_parse_context& context)
	{
		return context.begin(); // return position of '}'
	}

	// format by always writing it's value
	auto format(const Always40& obj, std::format_context& context) const
	{
		return std::format_to(context.out(), "{}", obj.get_value());
	}
};