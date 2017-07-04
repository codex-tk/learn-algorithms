#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

namespace codex {
	namespace alg {

		template < typename containerT >
		void merge_sort(containerT& container , order ord = order::ascending ) {

		}
		
} }

TEST_F(test_alg_fixture, merge) {
	codex::alg::merge_sort(this->samples);
	this->check_ascending();

}

TEST_F(test_alg_fixture, merge_r) {

	codex::alg::merge_sort(this->samples , codex::alg::order::descending );\
	//impl.sort(insertion<std::vector<int>>::order::descending);
	this->check_descending();
}
