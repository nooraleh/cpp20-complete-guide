#pragma once
#include <chrono>
#include <print>
#include <ranges>

namespace chr = std::chrono;
using namespace std::literals;

void print_meetings(std::chrono::year year)
{
	// every 5th of the month, every month for a given year
	for (const auto& month : std::views::iota(1u, 13u))
	{
		std::chrono::year_month_day ymd{ year / std::chrono::month{month} / std::chrono::day{5} };

		std::println("{}", ymd);
	}
}

void print_meetings2(std::chrono::year year)
{

	// every 5th of the month, every month for a given year
	for (const auto& month : std::views::iota(1u, 13u))
	{
		std::chrono::year_month_day ymd{ year / std::chrono::month{month} / std::chrono::day{5} };

		std::println("{}", ymd);

		// timepoint
		auto timepoint{ chr::sys_days{ymd} + 18h + 30min };
		std::println("\t we meet on {:%A %D at %R}", timepoint);
	}

}


void for_main1()
{
	using namespace std::chrono_literals;
	std::println("---------------- 2020 ----------------");
	print_meetings(2020y);

	std::println("---------------- 2021 ----------------");
	print_meetings(2021y);

	std::println("---------------- 2022 ----------------");
	print_meetings(2022y);

	std::println("---------------- 2023 ----------------");
	print_meetings(2023y);

	std::println("---------------- 2024 ----------------");
	print_meetings(2024y);
}

void for_main2()
{
	print_meetings2(2021y);

	// simple baby
	auto ymd1 = 2024y / std::chrono::December / 17d;
}

void for_main()
{
	for_main2();
}