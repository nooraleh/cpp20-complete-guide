module _19NTTPExtensions:_1905_lambdas_as_NTTPs;

import std;

template<std::invocable auto GET_VAT>
int add_tax(int value)
{
	return static_cast<int>(std::round(value * (1+ GET_VAT())));
}

void for_main_partition()
{
	auto get_default_tax = [] {return 0.19; };

	auto custom = []() consteval {return 0.22; };
	add_tax<custom > (100);

	//std::println("add_tax<get_default_tax>(100): {}", add_tax<get_default_tax>(100));
	//std::cout << "add_tax<[]{return 0.22; }>(100): " << add_tax < []() {return 0.22; } > (100) << '\n';
	//std::cout << "add_tax<[]{return 0.22; }>(100): " << add_tax < []() {return 0.22;  } > (100) << '\n';
	
	//std::println("add_tax<get_default_tax>(4199): {}", add_tax<get_default_tax>(4199));
	//std::println("add_tax<get_default_tax>(1950): {}", add_tax<get_default_tax>(1950));
}