#ifndef __alg_impl_test_alg_fixture_h__
#define __alg_impl_test_alg_fixture_h__

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

class test_alg_fixture : public ::testing::Test {
protected:
	std::vector<int> samples;
	virtual void SetUp();
	virtual void TearDown();
	
	void check_ascending();
	void check_descending();
};

#endif
