#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

namespace codex {
	namespace alg {
		namespace {
			template < typename valueT >
			bool ordered_compare(order ord, const valueT& v, const valueT& key) {
				if (ord == order::ascending)
					return v > key;
				return v < key;
			}
		}
		template < typename containerT >
		void insertion_sort(containerT& container , order ord = order::ascending) {
			for (int i = 1; i < (int)container.size(); ++i) {
				typedef typename containerT::value_type value_type;
				value_type key = container[i];
				int j = i - 1;
				while (j >= 0 && ordered_compare(ord, container[j], key)) {
					container[j + 1] = container[j];
					--j;
				}
				container[j + 1] = key;
			}
		}
	}
}
TEST_F(test_alg_fixture, insertion) {
	codex::alg::insertion_sort(this->samples);
	this->check_ascending();
	
}

TEST_F(test_alg_fixture, insertion_r) {
	codex::alg::insertion_sort(this->samples , codex::alg::order::descending );
	this->check_descending();
}
