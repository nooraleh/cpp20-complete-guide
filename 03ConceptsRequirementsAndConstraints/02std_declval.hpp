#pragma once
#include <utility>
#include <print>
/*
struct Default:
	- const-qualified member function foo 
	- returns int

struct NonDefault:
	- delete the default ctor
	- same foo as `Default`

for_main:
	- do a roundabout declaration of int n1 to without std::declval and using Default
	- do a roundabout declaration of int n1 with std::declval and using Default

	- do a roundabout declaration of int n1 to without std::declval and using NonDefault
	- do a roundabout declaration of int n1 with std::declval and using NonDefault

	- print out the result of the successful instantiations
*/

struct Default
{
public:
	int foo() const { return { 1 }; }
};

struct NonDefault
{
public:
	NonDefault() = delete;
	int foo() const { return { 1 }; }
};

void for_main()
{
	decltype(Default().foo()) n1{ 4 };
	decltype(std::declval<Default>().foo()) n2{ 5 };

	//decltype(NonDefault().foo()) n3{ 4 };
	decltype(std::declval<NonDefault>().foo()) n4{ 5 };

	std::println("n1: {}\nn2: {}\nn4: {}\n", n1, n2, n4);
}