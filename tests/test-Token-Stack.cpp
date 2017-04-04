/* File: test-Token-Stack.cpp
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "../Stack.h"
#include "../RPC.h"

TEST(Token_stack, token_constructor) {
    Token token('i', 90);
    ASSERT_TRUE(true);
    ASSERT_EQ(token.kind, 'i');
    ASSERT_EQ(token.value, 90);
}

TEST(Token_stack, token_stack_constructor) {
    ee::list::Stack<Token> stack(5);
    ASSERT_EQ(stack.capacity(), 5);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_FALSE(stack.isFull());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
