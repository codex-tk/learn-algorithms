#include <gtest/gtest.h>
#include "math_impl.hpp"

TEST( Eratosthenes, math) {
	static const int k_max_numbers = 1000;
	std::vector<char> numbers(k_max_numbers, 1);
	for (int i = 2; i * i <= k_max_numbers; ++i) {
		if (numbers[i] == 1) {
			for (int j = i; j	< k_max_numbers; j += i) {
				numbers[j] = 0;
			}
		}
	}
	/*
	for (std::size_t i = 0; i < k_max_numbers; ++i) {
		if ( numbers[i] == 1)
			PRINTF("Prime : %d\n", i);
	}*/
}

TEST(gcd, math) {
	ASSERT_EQ(codex::math::gcd(2, 4), 2);
	ASSERT_EQ(codex::math::gcd(2, 3), 1);
	ASSERT_EQ(codex::math::gcd(280, 30), 10);
	ASSERT_EQ(codex::math::gcd(30, 280), 10);
}
