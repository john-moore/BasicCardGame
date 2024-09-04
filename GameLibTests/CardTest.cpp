#include <gtest/gtest.h>



// Demonstrate some basic assertions.
TEST(Foo, BasicAssertions) {
    EXPECT_STRNE("hello", "foo");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}