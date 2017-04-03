/* File: test-Queue-array.cpp
 * Name: Paulo Lemus
 * Date: 3/30/2017
 */

/* This is a test file for ensuring that all the functions
 * and logic in the queue class are sound. Each test case
 * runs independantly and if all the tests "pass", then
 * the program will notify you upon running it.
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "../Queue.h"

TEST(Queue_array, capacity_constructor) {
    ee::array::Queue<int> test(2);
    ASSERT_TRUE(true);
}

TEST(Queue_array, capacity_n_size) {
    ee::array::Queue<int> queue(2);
    ASSERT_EQ(queue.capacity(), 2);
    ASSERT_EQ(queue.size(), 0);
}

TEST(Queue_array, isEmpty_n_isNotFull) {
    ee::array::Queue<int> queue(2);
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_FALSE(queue.isFull());
}

TEST(Queue_array, enqueue_and_size) {
    ee::array::Queue<int> queue(3);

    ASSERT_TRUE(queue.isEmpty());

    ASSERT_TRUE(queue.enqueue(1));
    ASSERT_EQ(queue.size(), 1);
    ASSERT_FALSE(queue.isEmpty());

    ASSERT_TRUE(queue.enqueue(2));
    ASSERT_EQ(queue.size(), 2);
    
    ASSERT_TRUE(queue.enqueue(3));
    ASSERT_EQ(queue.size(), 3);
    ASSERT_TRUE(queue.isFull());
}

// Test a basic case of dequing, ensure that
// dequeuing does not mess up any expected
// boolean return
TEST(Queue_array, peek_n_dequeue) {
    ee::array::Queue<int> queue(3);

    ASSERT_TRUE(queue.isEmpty());

    ASSERT_TRUE(queue.enqueue(1));
    ASSERT_EQ(queue.peek(), 1);
    ASSERT_EQ(queue.size(), 1);
    ASSERT_FALSE(queue.isEmpty());

    ASSERT_EQ(queue.dequeue(), 1);
    ASSERT_TRUE(queue.isEmpty());
}

// Long test to ensure that enqueing and
// dequeing to max capacity and to empty
// does not mess up the array indexing logic.
TEST(Queue_array, enqueuing_n_dequeuing) {
    ee::array::Queue<int> queue(3);

    int first  = 1;
    int second = 2;
    int third  = 3;
    int fourth = 4;
    int fifth  = 5;
    int sixth  = 6;

    ASSERT_TRUE(queue.enqueue(first));
    ASSERT_TRUE(queue.enqueue(second));
    ASSERT_TRUE(queue.enqueue(third));
    ASSERT_FALSE(queue.enqueue(fourth));
    ASSERT_EQ(queue.size(), 3);
    ASSERT_TRUE(queue.isFull());
    
    ASSERT_EQ(queue.peek(), first);
    ASSERT_EQ(queue.dequeue(), first);
    ASSERT_EQ(queue.size(), 2);
    
    ASSERT_EQ(queue.peek(), second);
    ASSERT_EQ(queue.dequeue(), second);
    ASSERT_EQ(queue.size(), 1);

    ASSERT_EQ(queue.peek(), third);
    ASSERT_TRUE(queue.enqueue(fourth));
    ASSERT_TRUE(queue.enqueue(fifth));
    ASSERT_FALSE(queue.enqueue(sixth));

    ASSERT_TRUE(queue.isFull());
    ASSERT_EQ(queue.size(), queue.capacity());
    ASSERT_EQ(queue.peek(), third);
    ASSERT_EQ(queue.dequeue(), third);

    ASSERT_EQ(queue.peek(), fourth);
    ASSERT_EQ(queue.dequeue(), fourth);
    ASSERT_EQ(queue.size(), 1);

    ASSERT_EQ(queue.peek(), fifth);
    ASSERT_EQ(queue.dequeue(), fifth);
    ASSERT_EQ(queue.size(), 0);
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_FALSE(queue.isFull());

    ASSERT_TRUE(queue.enqueue(sixth));
    ASSERT_EQ(queue.peek(), sixth);
    ASSERT_EQ(queue.size(), 1);
    ASSERT_FALSE(queue.isEmpty());
}

// Assert that use cannot dequeue from empty queue
TEST(Queue_array, empty_dequeue_throw) {
    ee::array::Queue<int> queue(3);

    queue.enqueue(1);
    ASSERT_EQ(queue.dequeue(), 1);
    ASSERT_THROW(queue.dequeue(), std::runtime_error);
    ASSERT_TRUE(queue.isEmpty());
}

// Assert that the output is as expected
TEST(Queue_array, print_check) {

    std::streambuf* coutbuf = std::cout.rdbuf();
    std::stringstream out;
    std::cout.rdbuf( out.rdbuf() );

    std::string expected = "Queue Contents: \n1\n2\n3\n";

    ee::array::Queue<int> queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.print();

    ASSERT_EQ(out.str(), expected);

    std::cout.rdbuf( coutbuf );
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
