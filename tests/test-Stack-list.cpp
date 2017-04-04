/* File: test-Stack-list.cpp
 * Name: Paulo Lemus
 * Date: 3/30/2017
 */

/* This is a test file for ensuring that all the functions
 * and logic in the stack class are sound. Each test case
 * runs independently and if all the tests "pass", then
 * the program will notify you upon running it.
 *
 * To execute this file, type the following from the root dir:
 * 1. export TESTCASE=test-Stack-list
 * 2. make test
 * 3. make run-test
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "../Stack.h"

TEST(Stack_list, capacity_constructor) {
    ee::list::Stack<int> stack(2);
    ASSERT_TRUE(true);
}

TEST(Stack_list, capacity_n_size) {
    ee::list::Stack<int> stack(2);
    ASSERT_EQ(stack.capacity(), 2);
    ASSERT_EQ(stack.size(), 0);
}

TEST(Stack_list, isEmpty_n_isNotFull) {
    ee::list::Stack<int> stack(2);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_FALSE(stack.isFull());
}

// Ensure that user pushing to stack updates
// the size, isEmpty, and isFull functions
TEST(Stack_list, push_and_size) {
    ee::list::Stack<int> stack(3);

    ASSERT_TRUE(stack.isEmpty());

    ASSERT_TRUE(stack.push(1));
    ASSERT_EQ(stack.size(), 1);
    ASSERT_FALSE(stack.isEmpty());

    ASSERT_TRUE(stack.push(2));
    ASSERT_EQ(stack.size(), 2);
    
    ASSERT_TRUE(stack.push(3));
    ASSERT_EQ(stack.size(), 3);
    ASSERT_TRUE(stack.isFull());
}

// Test a basic case of dequing, ensure that
// dequeuing does not mess up any expected
// boolean return
TEST(Stack_list, peek_n_pop) {
    ee::list::Stack<int> stack(3);

    ASSERT_TRUE(stack.isEmpty());

    ASSERT_TRUE(stack.push(1));
    ASSERT_EQ(stack.peek(), 1);
    ASSERT_EQ(stack.size(), 1);
    ASSERT_FALSE(stack.isEmpty());

    ASSERT_EQ(stack.pop(), 1);
    ASSERT_THROW(stack.pop(), std::runtime_error);
    ASSERT_TRUE(stack.isEmpty());
}

// Long test to ensure that pushing and
// popping to max capacity and to empty
// does not mess up the stack indexing logic.
TEST(Stack_list, pushing_n_popping) {
    ee::list::Stack<int> stack(3);

    int first  = 1;
    int second = 2;
    int third  = 3;
    int fourth = 4;
    int fifth  = 5;
    int sixth  = 6;

    ASSERT_TRUE(stack.push(first));
    ASSERT_TRUE(stack.push(second));
    ASSERT_TRUE(stack.push(third));
    ASSERT_FALSE(stack.push(fourth));
    ASSERT_EQ(stack.size(), 3);
    ASSERT_TRUE(stack.isFull());
    
    ASSERT_EQ(stack.peek(), third);
    ASSERT_EQ(stack.pop(), third);
    ASSERT_EQ(stack.size(), 2);
    
    ASSERT_EQ(stack.peek(), second);
    ASSERT_EQ(stack.pop(), second);
    ASSERT_EQ(stack.size(), 1);

    ASSERT_EQ(stack.peek(), first);
    ASSERT_TRUE(stack.push(fourth));
    ASSERT_TRUE(stack.push(fifth));
    ASSERT_FALSE(stack.push(sixth));

    ASSERT_TRUE(stack.isFull());
    ASSERT_EQ(stack.size(), stack.capacity());
    ASSERT_EQ(stack.peek(), fifth);
    ASSERT_EQ(stack.pop(), fifth);

    ASSERT_EQ(stack.peek(), fourth);
    ASSERT_EQ(stack.pop(), fourth);
    ASSERT_EQ(stack.size(), 1);

    ASSERT_EQ(stack.peek(), first);
    ASSERT_EQ(stack.pop(), first);
    ASSERT_EQ(stack.size(), 0);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_FALSE(stack.isFull());

    ASSERT_TRUE(stack.push(sixth));
    ASSERT_EQ(stack.peek(), sixth);
    ASSERT_EQ(stack.size(), 1);
    ASSERT_FALSE(stack.isEmpty());
}

// Assert that user cannot pop from empty stack
TEST(Stack_list, empty_pop_throw) {
    ee::list::Stack<int> stack(3);

    stack.push(1);
    ASSERT_EQ(stack.pop(), 1);
    ASSERT_THROW(stack.pop(), std::runtime_error);
    ASSERT_TRUE(stack.isEmpty());
}

// Assert that the output is as expected
TEST(Stack_list, print_check) {

    std::streambuf* coutbuf = std::cout.rdbuf();
    std::stringstream out;
    std::cout.rdbuf( out.rdbuf() );

    std::string expected = "Stack Contents:\n3\n2\n1\n";

    ee::list::Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.print();

    ASSERT_EQ(out.str(), expected);

    std::cout.rdbuf( coutbuf );
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
