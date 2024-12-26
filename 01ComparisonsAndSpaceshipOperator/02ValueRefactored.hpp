#pragma once
#include <print>


class Value
{
public:
	constexpr Value(long id) noexcept
		: m_id{ id }
	{}

	auto operator<=>(const Value&) const = default;

	// implicitly generated
	// auto operator==(const Value&) const = default // (1)
private:
	long m_id;
};


void for_main()
{
	Value v1{ 2 };
	Value v2{ 3 };

	std::println("v1 < v2 ? {}\n", v1 < v2);
}