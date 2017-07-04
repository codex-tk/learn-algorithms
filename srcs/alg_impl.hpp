#ifndef __codex_alg_impl_h__
#define __codex_alg_impl_h__

#include <list>

namespace codex {
	namespace alg {
		enum class order : int {
			ascending = 0,
			descending,
		};

		template < typename containerT >
		void insertion_sort(containerT& container, order ord = order::ascending) {

			typedef typename containerT::value_type value_type;
			struct _op {
				static bool ordered_compare(order ord, const value_type& v, const value_type& key) {
					if (ord == order::ascending)
						return v > key;
					return v < key;
				}
			};
			for (int i = 1; i < (int)container.size(); ++i) {
				value_type key = container[i];
				int j = i - 1;
				while (j >= 0 && _op::ordered_compare(ord, container[j], key)) {
					container[j + 1] = container[j];
					--j;
				}
				container[j + 1] = key;
			}
		}

		static const int k_use_insertion_sort = 4;

		template < typename containerT >
		void merge(containerT& container
			, std::size_t p
			, std::size_t q
			, std::size_t r 
			, order ord ) 
		{
			typedef typename containerT::value_type value_type;
			static std::vector< value_type > a(container.size());
			static std::vector< value_type > b(container.size());
			a.clear();
			b.clear();
			for (std::size_t i = p; i <= q; ++i) {
				a.push_back(container[i]);
			}
			for (std::size_t i = q + 1; i <= r; ++i) {
				b.push_back(container[i]);
			}
			std::size_t a_idx = 0;
			std::size_t b_idx = 0;
			for (int i = p; i <= r; ++i) {
				if (a_idx >= a.size())
					container[i] = b[b_idx++];
				else if (b_idx >= b.size())
					container[i] = a[a_idx++];
				else {
					if (a[a_idx] > b[b_idx]) {
						container[i] = ord == order::ascending ? b[b_idx++] : a[a_idx++];
					}
					else {
						container[i] = ord == order::ascending ? a[a_idx++] : b[b_idx++];
					}
				}
			}
		}

		template < typename containerT >
		void merge_sort(containerT& container, std::size_t p, std::size_t r , order ord ) {
			if (p < r) {
				std::size_t mid = (p + r) / 2;
				merge_sort(container, p, mid, ord);
				merge_sort(container, mid + 1, r, ord);
				merge(container, p, mid, r, ord);
			}
		}

		template < typename containerT >
		void merge_sort(containerT& container, order ord = order::ascending) {
			if (container.size() < k_use_insertion_sort)
				return insertion_sort(container, ord);
			merge_sort(container, 0, container.size() - 1, ord);
		}
	}
}

#endif