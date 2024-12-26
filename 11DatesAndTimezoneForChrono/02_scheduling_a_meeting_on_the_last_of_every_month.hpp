#pragma once
#include <chrono>
#include <print>
#include <ranges>

using namespace std::literals;


void print_last_every_month(std::chrono::year year)
{
	for (const auto& month : std::views::iota(1u, 13u))
	{
		std::chrono::year_month_day_last ymd_last{ year / std::chrono::month{month} / std::chrono::last };

		std::println("{}", ymd_last);

		auto tp{ std::chrono::sys_days(ymd_last) + 18h + 30min };

		std::println("Scheduled to meet on {:%A %D at %R}", tp);
	}
}

void for_main()
{
	print_last_every_month(2021y);
}