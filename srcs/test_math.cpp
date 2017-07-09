#include <gtest/gtest.h>
#include "math_impl.hpp"

TEST( Eratosthenes, math) {
	static const int k_max_numbers = 1000;
	std::vector<char> numbers(k_max_numbers, 1);
	std::vector<int> primes;
	for (int i = 2; i * i <= k_max_numbers; ++i) {
		if (numbers[i] == 1) {
			primes.push_back(i);
			for (int j = i; j < k_max_numbers; j += i) {
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

TEST( soas , math ) {
	ASSERT_EQ( codex::math::sum_of_arithmetic_sequence( 8 , 12 , 3) , 21);
	ASSERT_EQ( codex::math::sum_of_arithmetic_sequence( 10 , 12 , 3) , 12);
	ASSERT_EQ( codex::math::sum_of_arithmetic_sequence( 9 , 12 , 3) , 21);
	ASSERT_EQ( codex::math::sum_of_arithmetic_sequence( 11 , 12 , 3) , 12);
}

TEST(linear_equaction, math) {
	codex::math::point a;
	codex::math::point b;
	a.x = 1; a.y = 2;
	b.x = -2; b.y = 17;
	codex::math::linear_equation le = codex::math::linear_equation_solve(a, b);
	ASSERT_EQ(le.ax, -5);
	ASSERT_EQ(le.b, 7);
}
