#include <gtest/gtest.h>
// Demonstrate some basic assertions.
TEST(debugtest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

  EXPECT_GT(4,2);
}