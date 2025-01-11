module _02_consteval:_02_04_is_constant_evaluated_in_detail;

import std;

constexpr bool is_manifestly_constant_evaluated()
{
	return std::is_constant_evaluated();
}

// global or namespace scope
bool g1 = is_manifestly_constant_evaluated();					// true
const bool g2 = is_manifestly_constant_evaluated();				// true
static bool g3 = is_manifestly_constant_evaluated();			// true
static int g4 = g1 + is_manifestly_constant_evaluated();		// true + false (not manifest)
static int g5 = 42 + is_manifestly_constant_evaluated();		// 42 + true

void fmp1()
{
	// local scope
	bool l1 = is_manifestly_constant_evaluated();				// false
	const bool l2 = is_manifestly_constant_evaluated();			// false, true in 'int main()' though
	static bool l3 = is_manifestly_constant_evaluated();		// true inside int main(), false for 'for_main_partition'
	static int l4 = l1 + is_manifestly_constant_evaluated();	// false + false
	static int l5 = 42 + is_manifestly_constant_evaluated();	// false + true
}

consteval int func_consteval(int i)
{
	return i;
}

//constexpr int foo(int i)
//{
//	if (std::is_constant_evaluated())
//	{
//		return func_consteval(i);
//	}
//	else
//	{
//		return i + 1;
//	}
//}

void fmp2()
{
	int i{ 10 };
	constexpr int result = std::is_constant_evaluated() ? 20 : i;	// line (1)
	//constexpr int result2 = std::is_constant_evaluated() ? i : 20;	// line (2)
}

static void for_main_partition()
{
	fmp2();
}