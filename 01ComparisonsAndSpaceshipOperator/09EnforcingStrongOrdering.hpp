#pragma once
#include <string>

class Person
{
public:
	Person(std::string name, double value)
		: m_name{ name }, m_value{ value }
	{
	}

	std::strong_ordering operator<=>(const Person& rhs) const
	{
		// order by `m_name` first
		if (auto name_ordering = m_name <=> rhs.m_name; name_ordering != 0)
		{
			return name_ordering;
		}
		else // if name ordering is equal, order by `m_value` second
		{
			return std::strong_order(m_value,rhs.m_value);
		}
	}
public:
	std::string m_name;
	double m_value;
};


void for_main()
{

}