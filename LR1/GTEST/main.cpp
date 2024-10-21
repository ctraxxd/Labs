#include <gtest/gtest.h>

int sum(int a, int b) {
    return a + b;
}

TEST(TestTopic, TrivialEquality) {
    EXPECT_EQ(sum(3, 39), 42);
}

TEST(TestTopic, MoreEqualityTests) {
    EXPECT_FLOAT_EQ(23.23F, 23.23F);
    ASSERT_EQ(sum(-3, 4), 0) << "Oh no, a mistake!";
}

int main() {
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}
