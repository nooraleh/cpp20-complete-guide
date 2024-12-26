#pragma once
#include <bit>


template<auto VAL>
concept power_of_2 = std::has_single_bit(static_cast<unsigned>(VAL));

template<typename T, auto VAL>
requires power_of_2<VAL>
class Memory {};

void for_main()
{
	Memory<int, 2> m1;
	Memory<int, 8> m2;
}