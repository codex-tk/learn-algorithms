#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

template < typename elemT , template < typename elemT , class allocatorT > class containerT >
class merge{
public:
	typedef typename containerT< elemT, std::allocator<elemT>> container_type;
	merge(container_type& data )
		: _data(data)
	{}
private:
	container_type& _data;
};

TEST_F(test_alg_fixture, merge) {
	merge< int , std::vector > impl(this->samples);
	//impl.sort();
	this->check_ascending();

}

TEST_F(test_alg_fixture, merge_r) {
	merge< int , std::vector > impl(this->samples);
	//impl.sort(insertion<std::vector<int>>::order::descending);
	this->check_descending();
}
