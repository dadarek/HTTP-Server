#include "gtest/gtest.h"
#include "../lib/GTestTest.cpp"

TEST(SampleTest, SomethingHappens) {
  GTestTest test;
  EXPECT_EQ( 1, test.one() );
  EXPECT_TRUE( 1 < 2 );
  EXPECT_FALSE( 15 < 10 );
}

TEST(SampleTest, SomethingElseHappens) {
  GTestTest test;
  EXPECT_EQ( 100, test.hundred() );
  EXPECT_EQ( "Hi", "Hi" );
}

