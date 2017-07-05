#include "math_impl.hpp"
#include "gtest_helper.hpp"
namespace codex{
	namespace math {

		bool is_prime(int val) {
			if (val <= 1) return false;
			if (val <= 3) return true;
			if (val % 2 == 0 || val % 3 == 0) return false;
			return false;
		}


		int sum_of_arithmetic_sequence( int b , int e , int d ){
			/*
			int begin = b/d;
			if ( b % d != 0 )
				++begin;
			int end = e / d;
			int n = end - begin + 1;
			return d * ((n * ( begin + end )) / 2);*/
			int begin = (b - 1) / d; // 범위 앞의 항의 인덱스 선택 한다 ( 1,2,3,4, .. ) 순서의 등비수열 인덱스
			int end = e / d; // 마지막 항의 인덱스 선택
			int n = end - begin; // 개수
			int val = ( begin + 1 ) + end; // 범위 앞의 항을 선택했으니 +1 한다
			// ( 1 , 2 , 3 , 4, .. ) 등차수일 임을 감안하자
			return d * (n * val) / 2; // 등차 수열의 합공식 Sn = ( a1 + an ) / 2;
			// n{ 2a + ( n - 1 ) d } / 2
		}
	}
}
