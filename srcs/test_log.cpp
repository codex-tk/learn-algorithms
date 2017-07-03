#include <gtest/gtest.h>
#include <cmath>

double logB( double x , double base ){
  return log(x)/log(base);
}
TEST( BIG_O , selection_vs_merge ) {
  int i = 2;
  while ( true ){
    double a = pow( i , 2 ) * 8;
    double b = 64 * i * log(i);
    if ( a > b )
      break;
    ++i;
  }
  EXPECT_EQ( i , 27 );
}

TEST(BIG_O, alg) {
	int i = 2;
	while (true) {
		double a = 100 * pow(i, 2);
		double b = pow(2, i);
		if (b > a)
			break;
		++i;
	}
	EXPECT_EQ(i, 15);
}
