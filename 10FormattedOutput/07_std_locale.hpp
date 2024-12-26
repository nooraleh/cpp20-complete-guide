#pragma once
#include <format>
#include <iostream>
// internationalization

#ifdef _MSC_VER
	std::locale locG{ "deu_deu.1252" };
#else
	std::locale locG{ "de_DE" };
#endif

void for_main1()
{
	//std::cout << locG.name() << '\n';

	//std::cout << std::locale("").name() << '\n';

	std::format_to(std::ostreambuf_iterator<char>{std::cout}, locG, "{0} in {1} locale is: {0:L} ", 1'000.7, locG.name());
}

void for_main() { for_main1(); }