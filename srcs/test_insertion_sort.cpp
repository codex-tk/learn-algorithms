#include <gtest/gtest.h>
#include <cmath>
#include "test_alg_fixture.hpp"

template < class T >
class insertion {
public:
	enum class order : int {
		ascending = 0 ,
		descending ,
	};

	typedef typename T::value_type value_type;

	insertion(T& t)
		: _data(t)
	{

	}

	bool ordered_compare(order ord, value_type& d, value_type& key) {
		if (ord == order::ascending) {
			return d > key;
		}
		return d < key;
	}

	void sort(order ord = order::ascending) {
		for (int i = 1; i < (int)_data.size(); ++i) {
			value_type key = _data[i];
			int j = i - 1;
			while (j >= 0 && ordered_compare( ord , _data[j] , key )) {
				_data[j + 1] = _data[j];
				--j;
			}
			_data[j + 1] = key;
		}
	}
private:
	T& _data;
};


TEST_F(test_alg_fixture, insertion) {
	insertion< std::vector<int> > impl(this->samples);
	impl.sort();
	this->check_ascending();
	
}

TEST_F(test_alg_fixture, insertion_r) {
	insertion< std::vector<int> > impl(this->samples);
	impl.sort(insertion<std::vector<int>>::order::descending);
	this->check_descending();
}
