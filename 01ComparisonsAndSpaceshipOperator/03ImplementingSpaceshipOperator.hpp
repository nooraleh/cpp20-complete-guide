#pragma once
#include <compare>
#include <print>


class Value
{
public:
	// constexpr ctor taking long and ctor init list initializing m_id
	constexpr Value(long id) noexcept
		: m_id{id}
	{ }

	// define equality operator, invoking the equality operator of its member(s)
	bool operator==(const Value& rhs) const
	{
		return m_id == rhs.m_id;
	}

	// define spaceship operator, invoking the spaceship operator of its member(s)
	auto operator<=>(const Value& rhs) const
	{
		return m_id <=> rhs.m_id;
	}

private:
	long m_id;
};


void for_main()
{
	Value v1{ 2 };
	Value v2{ 3 };

	auto result = v1 < v2;
	std::println("v1 < v2 ? {}\n", v1 < v2);
}