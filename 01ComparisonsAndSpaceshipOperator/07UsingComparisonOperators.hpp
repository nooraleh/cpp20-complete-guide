#pragma once
#include <compare>
#include <utility>

class MyType
{
	//std::strong_ordering operator<=>(const MyType& rhs) const
	//{
	//	if (m_value == rhs.m_value)
	//	{
	//		return std::strong_ordering::equal;
	//	}
	//	else if (m_value < rhs.m_value)
	//	{
	//		return std::strong_ordering::less;
	//	}
	//	else
	//	{
	//		return std::strong_ordering::greater;
	//	}
	//}

	auto operator<=>(const MyType& rhs) const
	{
		return m_value <=> rhs.m_value;
	}

public:
	long m_value;
};

void for_main1()
{
	int x{ 17 }, y{ 42 };

	auto yield1 = x <=> y;			// std::strong_ordering::less
	auto yield2 = x <=> 17.0;		// std::partial_ordering::equivalent
	auto yield3 = &x <=> &x;		// std::strong_ordering::equal
	//auto yield4 = &x <=> nullptr;   // Compiler error: binary operator '<=>': unsupported operand types 'int *' and 'nullptr'
}

void for_main2()
{
	auto yield1 = (std::pair{ 42, 0 } <=> std::pair{ 42,7 });
}

void for_main()
{

}