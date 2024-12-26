#pragma once
#include <iostream>
#include <utility>
#include <print>
#include <concepts>

void process(int& x)
{
	std::println("l-value procesed: {}", x);
}

void process(int&& x)
{
	std::println("r-value procesed: {}", x);
}


template<typename T>
requires std::integral<typename std::remove_cvref_t<T>>
void forwarder(T&& t)
{
	process(std::forward<T>(t));
}


void for_main()
{
	int a = 10;

	forwarder(a);
	forwarder(14);
	forwarder(std::move(a));
}