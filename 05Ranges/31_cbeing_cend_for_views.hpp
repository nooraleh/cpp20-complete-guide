#pragma once
#include <vector>
#include <iostream>
#include <ranges>
#include <utility>
#include <type_traits>
#include <array>
#include <string_view>

//void print(std::ranges::input_range auto&& range)
//{
//    for (auto pos = std::ranges::cbegin(range); pos != std::ranges::cend(range); ++pos)
//    {
//        std::cout << *pos << ' ';
//    }
//    std::cout << '\n';
//}

template<std::ranges::input_range RANGE>
void print(RANGE&& range, const std::string_view comment)
{
    if constexpr (std::ranges::constant_range<RANGE>)
    {
        std::cout << comment << " then ";
        for (const auto& element : range)
        {
            std::cout << element << ' ';
        }
    }
    else
    {
        std::cout << "elese";
        print(
            std::views::as_const(std::forward<RANGE>(range)),
            "then"
        );
    }

}


std::array<int, 10> get_collection() { return {}; }

void for_main()
{
    auto collection = get_collection();
    print(collection, "collection");

    auto view_all = std::views::all(collection);
    print(view_all, "view_all");
}