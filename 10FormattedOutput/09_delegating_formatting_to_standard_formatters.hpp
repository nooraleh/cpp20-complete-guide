#pragma once
#include <format>
#include <print>
#include "10_always_42.hpp"

/*
- create an 'Always42' class in another .hpp file

- define a std::formatter for 'Always42'
	- formatter of int member function 'int_formatter'
	
	- parse
		- deletgate the parsing to the int formatter
	- format
		- delegate the formatting to the int formatter
*/

template<>
struct std::formatter<Always42>
{
public:
	template <class ParseContext>
	constexpr ParseContext::iterator parse(ParseContext& ctx) {
		return m_int_formatter.parse(ctx);
	}

	template <class FormatContext>
	FormatContext::iterator format(const Always42& ref, FormatContext& ctx) const {
		return m_int_formatter.format(ref.get_value(), ctx);
	}

	std::formatter<int> m_int_formatter;
};


void for_main()
{
	std::println("{}", Always42{});
}