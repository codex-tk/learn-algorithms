#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

TEST_F(test_alg_fixture, merge) {
	codex::alg::merge_sort(this->samples);
	this->check_ascending();
}

TEST_F(test_alg_fixture, merge_r) {
	codex::alg::merge_sort(this->samples , codex::alg::order::descending );
	this->check_descending();
}
