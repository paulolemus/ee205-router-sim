/* File: test-Queue-array.cpp
 * Name: Paulo Lemus
 * Date: 3/30/2017
 */

#include <gtest/gtest.h>
#include "Queue.h"

TEST(Queue_array, capacity_constructor) {
    ee::array::Queue<int> test(2);
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
