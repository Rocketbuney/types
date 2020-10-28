/*
 * @Author: Jack Thake 
 * @Date: 2020-10-27 15:39:59 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-28 09:52:09
*/

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

  TEST(stack, push_to_empty_stack) {
    types::stack stack(10);
    stack.push(1);
    EXPECT_EQ(stack.isempty(), false);
  }

  TEST(stack, push_to_stack_with_no_length) {
    types::stack stack;
    stack.push(1);
    EXPECT_EQ(stack.isempty(), true);
  }

  TEST(stack, peak_from_empty_stack) {
    types::stack stack;
    int temp = 15; /* arbitrary value */

    EXPECT_EQ(stack.isempty(), true);
    EXPECT_EQ(stack.peak(temp), false);
    EXPECT_EQ(15, temp); /* make sure temp wasn't modified */
  }

  TEST(stack, peak_from_populated_stack) {
    types::stack stack(1);
    int temp = 0;

    stack.push(1);
    EXPECT_EQ(stack.isempty(), false);
    EXPECT_EQ(stack.peak(temp), true);
    EXPECT_EQ(1, temp);
  }

  TEST(stack, pop_from_empty_stack) {
    types::stack stack;

    EXPECT_EQ(stack.isempty(), true);
    EXPECT_FALSE(stack.pop());
  }

  TEST(stack, pop_from_populated_stack) {
    types::stack stack(1);

    stack.push(1);
    EXPECT_EQ(stack.isempty(), false);
    EXPECT_TRUE(stack.pop());
    EXPECT_EQ(stack.isempty(), true);
  }
};