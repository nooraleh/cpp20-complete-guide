#pragma once

template<auto Val>
concept LessThan10 = Val < 10;

template<typename T, int size>
requires LessThan10<size>
class MyType
{ };