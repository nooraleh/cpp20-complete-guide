#pragma once
#include <format>
#include <string>
#include <iostream>
/*

- define an enum class for Color:
	- red, green, blue

- specialize a formatter for 'Color':
	- publically inherit the formatter for std::string

- format:
	- switch statement for assigning to an std::string 'value'
	- default value is "Color{}" formatted with a static cast to int

	- return and invoke the base classes std::string with 'value', contex

- format:
	- delegate formatting to the base class
*/

enum class Color {red, green, blue};

template<>
struct std::formatter<Color> : std::formatter<std::string>
{
public:
	template <class ParseContext>
	constexpr ParseContext::iterator parse(ParseContext& ctx)
	{
		return std::formatter<std::string>::parse(ctx);
	}

	template <class FormatContext>
	FormatContext::iterator format(const Color& ref, FormatContext& ctx) const
	{
		std::string value{  };

		switch (ref)
		{
		using enum Color;
		case red:
			value = "red";
			break;
		case green:
			value = "green";
			break;
		case blue:
			value = "blue";
			break;
		default:
			value = std::format("Color({})", static_cast<int>(ref));
		}

		return std::formatter<std::string>::format(value, ctx);
	}
};

void for_main()
{
	for (auto val : { Color::red, Color::green, Color::blue, Color{13} }) {
		// use user-provided formatter for enum Color:
		std::cout << std::format("Color {:_>8} has value {:02}\n",
			val, static_cast<int>(val));
	}

}