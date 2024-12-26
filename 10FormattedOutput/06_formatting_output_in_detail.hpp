#pragma once
#include <format>
#include <iostream>
#include <memory>

void for_main1()
{
	//[[maybe_unusued]] auto result = std::format("With format: {{}}: {}", 42);
}


void for_main2()
{
	std::wstring ws2 = std::format(
		L"{}",							// format string
		L"K\u00F6ln"					// argumet for the format string
	);
	std::wcout << ws2;
}


void for_main3()
{
	//std::unique_ptr<int> up_int = std::make_unique<int>(43);
	//std::format_to(std::ostreambuf_iterator{ std::cout }, "{}", up_int.get());

	//constexpr int i{ 42 };
	//const int* p = &i;
	//std::vformat_to(std::ostreambuf_iterator<char>{std::cout}, "{}",std::make_format_args(p));


	//std::unique_ptr<int> up_int = std::make_unique<int>(43);

	int i1 = 42;
	std::format_to(std::ostreambuf_iterator<char>{std::cout}, "{}", static_cast<void*>(&i1));
	//std::format("{}", static_cast<void*>(&i));
}

void for_main() { for_main3(); }