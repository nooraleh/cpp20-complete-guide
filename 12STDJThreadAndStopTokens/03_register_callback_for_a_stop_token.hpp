#pragma once
#include <thread>
#include <chrono>
#include <string>
#include <print>

using namespace std::literals;


void task(std::stop_token stop_token, std::string string, double value)
{
	std::stop_callback stop_callback{
		stop_token,                                 // pass in the stop_token 
		[] {std::println("stop callback called");
	}};
}


void for_main()
{
	std::jthread jt0{ task, "what am I going to do about it", 0.0 };

}