export module ModPerson2;

import <iostream>;
import <string>;

class Person					// note this is not exported
{
public:
	Person(std::string name)
		: m_name{ name }
	{
	}

	std::string get_name() const
	{
		return m_name;
	}

	friend std::ostream& operator<<(std::ostream& COUT, const Person& person)
	{
		return COUT << person.get_name();
	}

private:
	std::string m_name;
};


export Person get_person2(std::string s)
{
	return Person{ s };
}