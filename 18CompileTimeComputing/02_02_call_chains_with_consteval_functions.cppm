module _02_consteval:_02_02_call_chains_with_consteval_functions;


int compile_time_error()
{
	// not 'constexpr', 'consteval' => "pure runtime function"
	return -1;
}


consteval int next_two_digit_value(int value)
{
	// if value is within [0,99) this function will be a conpile-time error
	if (value < 0 || value >= 99)
	{
		return compile_time_error();
	}
	return value++;
}

// 'constexpr' functions cannot call 'consteval' functions for variables
static void for_main_partition()
{
	constexpr int i1 = next_two_digit_value(0);
	//constexpr int i3 = next_two_digit_value(99);
}