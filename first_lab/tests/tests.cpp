#include <iostream>
#include <gtest/gtest.h>
#include "../include/task.hpp"

TEST(task_func_test, random_test_set)
{
    ASSERT_TRUE(Solution::task("abc") == "bc");
}

TEST(task_func_test, only_vowels_test_set)
{
    ASSERT_TRUE(Solution::task("aaaaa") == "");
}

TEST(task_func_test, only_consonants_test_set)
{
    ASSERT_TRUE(Solution::task("bbbbbccccc") == "bbbbbccccc");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
