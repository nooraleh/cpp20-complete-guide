#pragma once
#include <print>
#include <thread>


void for_main()
{
	std::jthread jt1{
		[]
		{
			std::println("{}: printing from a new thread", std::this_thread::get_id());
		} 
	};


}