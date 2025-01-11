#pragma once
struct Truth
{
public:
	constexpr Truth()
		: m_value{ 42 }
	{}

	int m_value;
};

extern constinit Truth the_truth; // declare object