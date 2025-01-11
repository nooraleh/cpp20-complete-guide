module _02_consteval:_02_01_a_first_example;

import std;

constexpr bool is_prime(int value)
{
	for (int i{ 2 }; i <= (value / 2); ++i)
	{
		if ((value % i) == 0)
		{
			return false;
		}
	}
	return value > 1;
}

template<int N>
consteval std::array<int, N> prime_numbers()
{
	std::array<int, N> primes;
	std::size_t idx{ 0 };

	for (int val{ 1 }; idx < N; ++val)
	{
		if (is_prime(val))
		{
			primes[idx++] = val;
		}
	}
	return primes;
}

static void for_main_partition()
{
	auto primes = prime_numbers<100>();

	for (auto prime : primes)
	{
		std::cout << prime << '\n';
	}
}