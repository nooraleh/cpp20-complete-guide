#pragma once
#include <concepts>
#include <print>
#include <string>

template<std::integral T>
consteval bool gcd(T a, T b)
{
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return (a > 0) ? a : -a; // Ensure GCD is always positive
}


template<typename T, int MIN, int MAX>
//requires(gcd(MIN, MAX) > 1)
void foo()
{
    std::println("MIN: {}", MIN);
}


template<typename T>
requires false
void print(const T&)
{
    // implementation ...
}

void for_main()
{
    foo<std::string, 6, 9>();
}