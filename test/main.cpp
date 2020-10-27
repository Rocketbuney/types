#include <types/types.h>
#include <gtest/gtest.h>

#include <iostream>
using namespace std;

TEST(First, test1) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}