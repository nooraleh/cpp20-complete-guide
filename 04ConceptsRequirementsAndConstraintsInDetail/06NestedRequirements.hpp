#pragma once
#include <concepts>
#include <type_traits>
#include <print>


// write a concept that ensures that:
// both 1) operator* and 2) operator[] are valid and yield the same type for a given type

template<typename T>
concept dereference_and_index_match = requires(T t) { requires std::same_as<decltype(*t), decltype(t[0])>; };