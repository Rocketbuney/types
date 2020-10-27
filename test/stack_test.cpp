#include <types/types.h>
#include <gtest/gtest.h>

namespace {
  TEST(stack, instantiate_empty_stack_with_length) {
    types::stack stack(10);
    EXPECT_EQ(stack.isempty(), true);
  }

  TEST(stack, instantiate_stack_no_length) {
    types::stack stack;
    EXPECT_EQ(stack.isempty(), true);
  }
};