#pragma once
#include <thread>
#include <print>
#include <string>
#include <chrono>

using namespace std::literals;

void task(std::stop_token stop_token, std::string string_view, double)
{
	std::this_thread::sleep_for(1s);
	std::println("{}: entered task scope.", std::this_thread::get_id());

	std::println("{}: exiting task scope.", std::this_thread::get_id());

	std::stop_callback stop_callback{
	stop_token,
	[]()
	{
		std::println("{}: stop_callback called", std::this_thread::get_id());
	}
	};
}

void for_main()
{
	std::println("{}: spawning thread", std::this_thread::get_id());
	std::jthread jt0{ task, std::string{"hello"}, 42.0 };
	jt0.request_stop();
	

	auto id_jt0 = jt0.get_id();
	std::println("{}: thread {} spawned", std::this_thread::get_id(), id_jt0);
}