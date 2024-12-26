#pragma once
#include <chrono>
#include <thread>
#include <ranges>
#include <print>

using namespace std::literals;

void for_main()
{
	std::jthread jt0{ [](std::stop_token stop_token)
		{
			for (auto&& i : std::views::iota(0, 10))
			{
				std::println("{}: printing value {}", std::this_thread::get_id(), i);

				if (stop_token.stop_requested())
				{
					return;
				}
				std::this_thread::sleep_for(1s);
			}
		}
	};
	auto jt0_id = jt0.get_id();
	std::this_thread::sleep_for(5s);

	jt0.request_stop();
	std::println("{}: stopped thread {}", std::this_thread::get_id(), jt0_id);
}