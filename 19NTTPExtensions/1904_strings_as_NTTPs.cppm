module _19NTTPExtensions:_1904_strings_as_NTTPs;

import std;

template<auto PREFIX>
class Logger
{
public:
	void log(std::string_view msg) const
	{
		std::cout << PREFIX << msg << '\n';
	}
};

template<std::size_t N>
struct Str
{
	char chars[N];
	const char* value()
	{
		return chars;
	}

	friend std::ostream& operator<<(std::ostream& COUT, const Str& s)
	{
		return COUT << s.chars;
	}
};


static void for_main_partition()
{
	Logger < Str{ "> " } > logger;
	logger.log("hello"); // ouput: "> hello"
}