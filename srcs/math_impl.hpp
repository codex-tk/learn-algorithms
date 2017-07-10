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

		template < typename valueT >
		valueT lcm( valueT x , valueT y ) {
			/*
			valueT gcd_val = gcd( x, y);
			valueT xx = x / gcd_val;
			valueT yy = y / gcd_val;
			return gcd_val * xx * yy;
			// 소인수분해 기준
			*/
			// X = G * x , Y = G * y
			// X * Y = G * G * x * y
			// X * Y / G = G * x * y
			return x * y / gcd( x , y );
		}
		int sum_of_arithmetic_sequence( int b , int e , int d);

		struct linear_equation {
			double ax;
			double b;
		};

		struct point {
			double x;
			double y;
		};

		linear_equation linear_equation_solve(const point& a, const point& b);


	}
}

#endif
