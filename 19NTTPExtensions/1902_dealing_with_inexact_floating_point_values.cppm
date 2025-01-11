module _19NTTPExtensions:_1902_dealing_with_inexact_floating_point_values;

import std;

template<typename T1, typename T2>
void print_is_same(std::string_view command)
{
	std::println("{} ? {}", command, std::is_same_v<T1, T2>);
}

template<double VAL>
class MyClass {};


void fmp_1902()
{
	std::cout << std::boolalpha;
	std::cout << std::is_same_v<MyClass<42.0>, MyClass<17.7>> // always false
		<< '\n';
	std::cout << std::is_same_v<MyClass<42.0>, MyClass<126.0 / 3>> // true or false
		<< '\n';
	std::cout << std::is_same_v<MyClass<42.7>, MyClass<128.1 / 3>> // true or false
		<< "\n\n";

	std::cout << std::is_same_v<MyClass<0.1 + 0.3 + 0.00001>,
		MyClass<0.3 + 0.1 + 0.00001>> // true or false
		<< '\n';
	std::cout << std::is_same_v<MyClass<0.1 + 0.3 + 0.00001>,
		MyClass<0.00001 + 0.3 + 0.1>> // true or false
		<< "\n\n";
}

static void for_main_partition()
{
	fmp_1902();
}