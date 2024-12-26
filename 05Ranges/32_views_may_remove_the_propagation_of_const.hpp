#pragma once
#include <vector>
#include <iostream>
#include <ranges>
#include <utility>
#include <type_traits>
#include <array>

void print(std::ranges::input_range auto&& range)
{
    for (const auto& element : range)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void f(T&& element) // universal references to preserve constness
{
    if constexpr (std::is_const_v<std::remove_reference_t<T>>)
    {
        std::cout << "is const\n";
    }
    else
    {
        std::cout << "is NOT const\n";
    }
}

template<typename T>
void modify_constrange(const T& range)
{
    range.front() += 1;
}

void for_main1()
{
    const std::vector<int> vector = { 1, 2, 3 };
    f(vector.at(1));
}

void for_main2()
{
    std::array<int, 10> collection{}; // array of ten ints default initialized to 0;
    //modify_constrange(collection);
}

void for_main3()
{
    std::array<int, 10> collection{};
    std::ranges::take_view take_view{ collection, 5 };
    modify_constrange(take_view);
    print(collection);

    modify_constrange(std::views::all(collection));
    print(collection);

}

std::array<int, 10> get_collection()
{
    return {};
}

void for_main4()
{
    // modifying views on r-values 'owning_view's which propogate const
    // is a compile-time error
    //modify_constrange(get_collection() | std::views::take(5));

    std::array<int, 10> collection{};
    //modify_constrange(collection | std::views::take(5) | std::views::as_const);
    modify_constrange(collection | std::views::take(5));
    print(collection);
}


void for_main()
{
    for_main4();
}