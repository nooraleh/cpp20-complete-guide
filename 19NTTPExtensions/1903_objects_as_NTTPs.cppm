module; // global module fragment

#include <cassert>

module _19NTTPExtensions:_1903_objects_as_NTTPs;

import std;

struct Tax
{
public:
	//constexpr Tax(double v)
	//	requires {v >= 0 && v < 1; }
	//	: m_value{ v }
	//{
	//	//assert(v >= 0 && v < 1);
	//}

	constexpr Tax(double v)
		: m_value{ v }
	{
	}

	friend std::ostream& operator<<(std::ostream& COUT, const Tax& tax)
	{
		return COUT << tax.m_value;
	}

	double m_value;
};

template<>
struct std::formatter<Tax>
{
    template<class ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template<class FmtContext>
    FmtContext::iterator format(const Tax& tax, FmtContext& ctx) const
    {
		return std::format_to(ctx.out(), "{}", tax.m_value);
    }
};

template<Tax VAT>
int add_tax(int value)
{
	return static_cast<int>(std::round((1 + VAT.m_value) * value));
}


void fmp_1903()
{
	constexpr Tax tax{ 0.19 };

	std::println("tax: {}", tax);

	std::println("add_tax<tax>(100): {}", add_tax<tax>(100));
	std::println("add_tax<tax>(4199): {}", add_tax<tax>(4199));
	//std::println("add_tax<Tax{0.07}>(1950): {}", add_tax<Tax{0.07}>(1950));
}


constexpr int foo()
{
	return 42;
}


struct Lit
{
	int x = foo();
	int y;

	constexpr Lit(int i)
		: y{i}
	{ }
};


struct Data
{
	int i;
	std::array<double, 5> vals;
	Lit lit;
};


template<auto OBJ>
void func()
{
	std::cout << typeid(OBJ).name() << '\n';
}


void fmp_190301()
{
	func < Data{ 42, {1, 2, 3}, 42 } > ();

	constexpr Data d2{ 1, {2}, 3 };
	func<d2>();
}


template<auto VAL>
class MyClass
{
};


void fmp_190302()
{
	// std::pair<> and std::array<> values as non-type template parameters
	[[maybe_unused]] MyClass < std::pair{ 47, 11 } > mcp;
	[[maybe_unused]] MyClass < std::array{ 0, 8, 15 } > mca;
}

static void for_main_partition()
{
	fmp_190302();
}