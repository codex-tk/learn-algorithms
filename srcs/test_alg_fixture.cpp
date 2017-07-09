#include "test_alg_fixture.hpp"

namespace {
	static const int k_max_elements = 10240;
}

void test_alg_fixture::SetUp() {
	for (int i = 0; i < k_max_elements; ++i) {
		this->samples.push_back(i);
	}
	std::random_shuffle(this->samples.begin(), this->samples.end());
}

void test_alg_fixture::TearDown() {
	

}

void test_alg_fixture::check_ascending() {
	for (int i = 0; i < this->samples.size(); ++i) {
		ASSERT_EQ(i, samples[i]);
	}
}

void test_alg_fixture::check_descending() {
	for (int i = 0; i < this->samples.size(); ++i) {
		ASSERT_EQ(k_max_elements - i - 1, samples[i]);
	}
}
