project( alg-impl )

include_directories( ${gtest_SOURCE_DIR}/include )

if( MSVC )
	add_definitions (/D _CRT_SECURE_NO_WARNINGS)
else()
	add_definitions( -Wall -std=c++11 -o2 -g -ggdb )
	if( APPLE )

	else()

	endif()
endif()

add_executable( alg-impl
	test_build_test.cpp
	test_log.cpp
	test_insertion_sort.cpp
  test_alg_fixture.hpp
  test_alg_fixture.cpp
  test_merge_sort.cpp
	alg_impl.hpp
	test_math.cpp
	math_impl.hpp
	math_impl.cpp
	gtest_helper.hpp
	test_hanoi.cpp
)

target_link_libraries( alg-impl
 gtest
 gtest_main
)
