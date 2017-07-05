#ifndef __math_impl_h__
#define __math_impl_h__

#include <iostream>

namespace codex {
	namespace math {
		
		template < typename valueT >
		valueT gcd( valueT x,  valueT y) {
			if ( x < y ) std::swap(x, y);
			// gcd( x , y ) == gcd( y , x % y );
			while (y){
				x = x % y; // x => x%y , y => y -> swap -> y , x% y
				std::swap(x , y);
			}
			return x;
		}

	} 
}

#endif
