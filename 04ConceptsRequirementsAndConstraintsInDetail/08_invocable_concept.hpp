#pragma once
#include <concepts>
#include <string>
#include <print>

//namespace nb
//{
//	template<typename FUNC, typename... ARGS>
//	concept invocable = requires (FUNC&& f, ARGS&&... args)
//	{
//		std::invoke(std::forward<FUNC>(f), std::forward<ARGS>(args)...);
//	};
//}

template<std::invocable<int, std::string> INVOCABLE>
void call_me_baby(INVOCABLE&& invocable, int number, std::string my_new_baby)
{
	invocable(number, my_new_baby);
}

void f(int arg1, std::string arg2)
{
	std::println("{}: {}", arg1, arg2);
}



void for_main()
{
	auto f2 = [](int arg1, std::string arg2) {std::println("{}: {}", arg1, arg2); };
	call_me_baby(f2, 991, "Constable George");
}