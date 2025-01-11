export module _01_constinit;

import std;

// you can use constinit whenever you declare a static or global variable

// global
constinit auto i{ 42 };

int get_next_class_id()
{
	static constinit int max_id{ 0 };
	return ++max_id;
}

class MyType
{
	static inline constinit long max = sizeof(int) * 1'000;
};

constexpr std::array<int, 5> get_collection()
{
	return { 1, 2, 3, 4, 5 };
}

constinit auto global_collection = get_collection();

void for_main1()
{
	std::cout << i << " " << global_collection[0] << '\n';
	i *= 2;
	global_collection = {};
	std::cout << i << " " << global_collection[0] << '\n';
}

consteval int f(int x)
{
	return x + 3;
}

void for_main2()
{
	static constexpr auto x = f(1);
	static constinit auto y = x;
}

// global scope
constinit std::unique_ptr<int> up;
constinit std::shared_ptr<int> sp;

class Example
{
	//static constinit int value1{ 42 };		// ERROR
	static inline constinit int value2{ 42 };	// OK
};

void for_main3()
{
	thread_local int x1{ 0 };
	thread_local constinit int x2{ 0 };
}

export void for_main()
{
	for_main2();
}