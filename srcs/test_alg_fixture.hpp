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
	
	void CheckSorted();
	void CheckRSorted();
};

#endif
