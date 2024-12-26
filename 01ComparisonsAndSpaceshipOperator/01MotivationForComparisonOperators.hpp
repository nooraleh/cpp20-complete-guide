#pragma once
class Value
{
public:
	constexpr Value(long id) noexcept
		: m_id{id}
	{}

	// equality operators
	bool operator==(const Value& rhs) const
	{
		return m_id == rhs.m_id;
	}

	bool operator!=(const Value& rhs) const
	{
		return !(*this == rhs);
	}

	// relational operators
	bool operator<(const Value& rhs) const
	{
		return m_id < rhs.m_id;
	}

	bool operator<=(const Value& rhs) const
	{
		return (*this < rhs) && (*this == rhs);
	}

	bool operator>(const Value& rhs) const
	{
		return !(*this <= rhs);
	}

	bool operator>=(const Value& rhs) const
	{
		return !(*this < rhs);
	}

private:
	long m_id;
};