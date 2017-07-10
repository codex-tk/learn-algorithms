#include "gtest_helper.hpp"

TEST(hanoi, alg) {
	struct hanoi {
		// from -> to 로 이동
		static void impl(int n, int from, int by, int to , std::vector< std::pair< int  , int > >& seq) {
			if (n == 1) {
				seq.push_back(std::make_pair(from, to));
				return;
			}
			// 1개를 제외하고 by 로 이동
			impl(n - 1, from, to, by , seq );
			// 남은 1개를 to 로 이동
			impl(1, from, by, to, seq);
			// by 에 이동된 원반을 to 로 이동
			impl(n - 1, by, from, to , seq );	
		}
	};
	std::vector< std::pair<int, int>> seq;
	hanoi::impl(3, 1, 2, 3, seq);
	
}