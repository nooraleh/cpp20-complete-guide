module _19NTTPExtensions:_19_constraints_on_NTTPs;

import std;

template<double WEIGHT>
concept healthy_BMI = requires{WEIGHT >= 18.5 && WEIGHT <= 24.9; };


// floating-point values as NTTPs
template<double VAT>
int add_tax(int value)
{
	return static_cast<int>(std::round(value * (1+ VAT)));
}

void fmp_1901()
{
	std::println("{}", add_tax<0.19>(100));
	std::println("{}", add_tax<0.19>(4199));
	std::println("{}", add_tax<0.07>(1950));
}

static void for_main_partition()
{
	fmp_1901();
}