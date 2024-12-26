#pragma once
#include <chrono>
#include <thread>

using namespace std::literals;

bool g_flag{ false };

void busy_waiting()
{
	while(!g_flag)
	{
		// no breaks - does nothing other than constantly check the flag
		// leads to high CPU usage
	}
}

void active_polling1()
{
	while (!g_flag)
	{
		// hint to the implementation to allow other threads to run
		std::this_thread::yield();
	}
}

void active_polling2()
{
	while (!g_flag)
	{
		// 10ms break each time
		std::this_thread::sleep_for(10ms);
	}
}