#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

void insertion_sort(std::vector< int >& arr) {
	for (int i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}

void insertion_sort_r(std::vector< int >& arr) {
	for (int i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] < key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}


TEST_F(test_alg_fixture, insertion) {
	insertion_sort(this->samples);
	this->CheckSorted();
	
}

TEST_F(test_alg_fixture, insertion_r) {
	insertion_sort_r(this->samples);
	this->CheckRSorted();
}
