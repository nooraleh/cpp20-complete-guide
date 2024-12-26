#pragma once
#include <chrono>
#include <print>
#include <ranges>

using namespace std::literals;

void print_meetings(std::chrono::year year)
{
	for (const auto& month : std::views::iota(1u, 13u))
	{
		std::chrono::year_month_weekday ym_weekday{
			year / std::chrono::month{month} / std::chrono::Monday[1]};
		std::println("{}", ym_weekday);
		
		auto tp{ std::chrono::sys_days{ym_weekday} + 18h + 30min };
		std::println("Scheduled to meet on {:%A %D at %R}", tp);
	}
}


void for_main()
{
	print_meetings(2021y);
}