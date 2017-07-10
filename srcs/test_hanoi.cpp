#include "gtest_helper.hpp"

TEST(hanoi, alg) {
	struct hanoi {
		// from -> to �� �̵�
		static void impl(int n, int from, int by, int to , std::vector< std::pair< int  , int > >& seq) {
			if (n == 1) {
				seq.push_back(std::make_pair(from, to));
				return;
			}
			// 1���� �����ϰ� by �� �̵�
			impl(n - 1, from, to, by , seq );
			// ���� 1���� to �� �̵�
			impl(1, from, by, to, seq);
			// by �� �̵��� ������ to �� �̵�
			impl(n - 1, by, from, to , seq );	
		}
	};
	std::vector< std::pair<int, int>> seq;
	hanoi::impl(3, 1, 2, 3, seq);
	
}