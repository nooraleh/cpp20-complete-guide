#pragma once
#include <string>

class Person
{
public:
	Person(std::string name, double value)
		: m_name{name}, m_value{value}
	{ }

	auto operator<=>(const Person& rhs) const
		-> std::common_comparison_category_t < decltype(std::string{} <=> std::string{}), decltype(double{} <=> double{}) >
	{
		// order by `m_name` first
		if (auto name_ordering = m_name <=> rhs.m_name; name_ordering != 0)
		{
			return name_ordering;
		}
		else // if name ordering is equal, order by `m_value` second
		{
			return m_value <=> rhs.m_value;
		}
	}
public:
	std::string m_name;
	double m_value;
};



void for_main()
{
	//std::string{}.operator<=>(std::string{});
	//std::common_comparison_category_t<
	//	decltype(std::string{}.operator<=>(std::string{})), decltype(m_value <=> rhs.m_value) >
	std::common_comparison_category_t < decltype(std::string{} <=> std::string{}), decltype(int{} <=> int{}) > ;

	//std::string s1{ "test" }, s2{"test2"};
	//double i1{ 2 }, i2{ 4 };
	//std::common_comparison_category_t<decltype(s1 <=> s2), decltype(i1 <=> i2)> _type;
	
	//static_assert(
	//	std::common_comparison_category_t<decltype(s1 <=> s2), decltype(i1 <=> i2)> == std::partial_ordering,
	//	"asd");
}