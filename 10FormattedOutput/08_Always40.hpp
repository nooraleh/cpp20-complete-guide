#pragma once
#include <format>
#include <sstream>
#include <print>

class Always40
{
public:
	int get_value() const
	{
		return 40;
	}
};

template<>
struct std::formatter<Always40>
{
public:
    template<class ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
        auto it = ctx.begin();

        // if we're at '}'
        if (it == ctx.end())
        {
            return it;
        }

        // validation
        if (it != ctx.end() && *it != '}')
        {
            throw std::format_error("Invalid format args for Always40.");
        }

        return it;
    }


    template<class FmtContext>
    FmtContext::iterator format(const Always40& always40, FmtContext& ctx) const
    {
        return std::format_to(ctx.out(), "Always40({})", always40.get_value());
    }
};


void for_main()
{
    // calls std::format under-the-hood
    std::print("{}", Always40{});
}