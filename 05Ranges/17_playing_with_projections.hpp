#pragma once
#include <ranges>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <format>
#include <string_view>
#include <algorithm>

struct Person
{
public:
	std::string m_name;
	int m_age;
};

void print(std::ranges::input_range auto range, const std::string_view comment)
{
	std::cout << comment;
	for (const auto& element : range)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';
}

std::ostream& operator<<(std::ostream& COUT, const Person& person)
{
	COUT << std::format("Person({}, {})", person.m_name, person.m_age);
	return COUT;
}

int generate_random_age()
{
	std::random_device random_device{};
	std::mt19937 mersenne_twister_generator{ random_device() };
	std::uniform_int_distribution age_distribution{ 13, 90 };
	return age_distribution(mersenne_twister_generator);
}

std::vector<Person> generate_people()
{
	return {
		{"John", generate_random_age()},
		{"Adam", generate_random_age()},
		{"George", generate_random_age()},
		{"Anthony", generate_random_age()},
		{"Joshu", generate_random_age()},
		{"Deontay", generate_random_age()},
	};
}

void for_main()
{
	auto people = generate_people();
	print(people, "people generated, pre-sorting by age: ");

	std::ranges::sort(people, std::ranges::less{}, &Person::m_age);
	print(people, "people generated, post-sorting by age: ");


}