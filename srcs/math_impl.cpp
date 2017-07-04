#include "math_impl.hpp"

namespace codex{
	namespace math {

		bool is_prime(int val) {
			if (val <= 1) return false;
			if (val <= 3) return true;
			if (val % 2 == 0 || val % 3 == 0) return false;
			return false;
		}
	}
}