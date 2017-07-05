#ifndef __math_impl_h__
#define __math_impl_h__

#include <iostream>

namespace codex {
	namespace math {

		template < typename valueT >
		valueT gcd( valueT x,  valueT y) {
			if ( x < y ) std::swap(x, y);
			//
			// gcd( x , y ) == gcd( y , x % y );
			while (y){
				x = x % y; // x => x%y , y => y -> swap -> y , x% y
				std::swap(x , y);
			}
			return x;
		}

		typename < typename valueT >
		valueT lcm( valueT x , valueT y ) {
			/*
			valueT gcd_val = gcd( x, y);
			valueT x_reminder = x % gcd_val;
			valueT y_reminder = y % gcd_val;
			return gcd_val * x_reminder * y_reminder;
			// 소인수분해 기준
			*/
			// X = G * x , Y = G * y
			// X * Y = G * G * x * y
			// X * Y / G = G * x * y
			// profit!
			return x * y / gcd( x , y );
		}
		int sum_of_arithmetic_sequence( int b , int e , int d);

	}
}

#endif
