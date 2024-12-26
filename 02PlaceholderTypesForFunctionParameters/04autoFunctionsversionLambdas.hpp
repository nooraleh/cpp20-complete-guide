#pragma once
#include <vector>
#include <string>
#include <algorithm>

struct Person
{
public:
	std::string get_name() const
	{
		return m_name;
	}

	std::string m_name;
};

bool less_by_name_func(const auto& c1, const auto& c2)
{
	return c1.get_name() < c2.get_name();
}


void for_main()
{
	std::vector<Person> persons = { Person{"John"}, Person{"Jacob"}, Person{"Jane"} };

	std::sort(persons.begin(), persons.end(), less_by_name_func<Person, Person>);
}