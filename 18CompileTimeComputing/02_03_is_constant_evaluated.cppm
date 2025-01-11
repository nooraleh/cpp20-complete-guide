module _02_consteval:_02_03_is_constant_evaluated;

import std;

constexpr int len(const char* s)
{
	if (std::is_constant_evaluated())
	{
		// compile-time context
		int idx{ 0 };
		while (s[idx] != '\0')
		{
			++idx;
		}
		return idx;
	}
	else
	{
		// runtime context
		return std::strlen(s);
	}
}

void for_main1()
{
	constexpr int l1{ len("Hello") }; // 
	int l2{ len("hello") };
}


// convert an integral value to a string both at compile-time and runtime
constexpr std::string as_string(long long value)
{
	if (std::is_constant_evaluated())
	{
		if (value == 0)
		{
			return "0";
		}
		if (value < 0)
		{
			return "-" + as_string(-value);
		}

		std::string s = as_string(value / 10) + std::string(1, value % 10 + '0');
		if (s.size()  > 1 && s[0] == '0') // skip leading 0 if there if one
		{
			s.erase(0, 1);
		}
		return s;
	}
	else
	{
		// although I have my reservation, a truly runtime computation would require
		// vformat, no? TODO: test
		return std::format("{}", value);
	}
}


static void for_main_partition()
{
	std::println("{}", as_string(453));
}