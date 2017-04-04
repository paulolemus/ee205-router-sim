/* File: Queue.h
 * Name: Paulo Lemus
 * Date: 3/16/2017
 */

#ifndef EE_ARRAY_QUEUE_H_
#define EE_ARRAY_QUEUE_H_

#include <exception>
#include <stdexcept> 

namespace ee {
namespace array {


//////////////////////////////
//       DECLARATIONS       //
//////////////////////////////

template <typename T>
class Queue {

    int cap;
    int head;
    int tail;
    int sz;
    T* array;

public:
    Queue(int capacity);
    int  size();
    int  capacity();
    bool isEmpty();
    bool isFull();
    bool enqueue(const T& data);
    T    dequeue();
    T&   peek();
    void print();

};

/////////////////////////////
//     IMPLEMENTATION      //
/////////////////////////////

template <typename T>
Queue<T>::Queue(int capacity) : 
    cap(capacity), 
    head(0),
    tail(0),
    sz(0), 
    array(new T[capacity]) {}


template <typename T>
int Queue<T>::size() { return sz; }
template <typename T>
int Queue<T>::capacity() { return cap; }
template <typename T>
bool Queue<T>::isEmpty() {
    return (sz <= 0);
}
template <typename T>
bool Queue<T>::isFull() {
    return (sz >= cap);
}

/* ENQUEUE:
 * The head always points to the oldest element entered into the queue.
 * The tail always points to the latest element entered into the queue.
 * When enqueueing, the tail will increment before adding the data only if
 * the size is greater than 0. Otherwise, both head and tail point to the same element.
 */
template <typename T>
bool Queue<T>::enqueue(const T& data) {

    if(sz < cap) {

        if(sz > 0) {
            tail = (tail + 1) % cap;
        }
        array[tail] = data;
        sz++;
        return true;
    } 
    else return false;
}

/* DEQUEUE:
 * You can only dequeue when the size is greater than 0, 
 * or in other words when there are elements in the list.
 * If a list is empty and you attempt to dequeue, a runtime
 * error is thrown.
 */
template <typename T>
T Queue<T>::dequeue() {

    if(sz > 0) {
        int position = head;
        sz--;
        if(head != tail) head = (head + 1) % cap;
        return array[position];
    }
    throw std::runtime_error("dequeued from empty queue");
}
template <typename T>
T& Queue<T>::peek() {
    if(sz > 0) {
        return array[head];
    }
    throw std::runtime_error("Peeked on empty queue");
}
template <typename T>
void Queue<T>::print() {
    std::cout << "contents:";
    if(sz <= 0) std::cout << " Empty!";
    else if(head == tail && sz > 0) std::cout << " " << array[head];
    else if(sz > 0) {
        int index = head;
        for (int i = 0; i < sz; ++i) {
            std::cout << " " << array[index];
            index = (index + 1) % cap;
        }
    }
    std::cout << std::endl;
}


} // array namespace
} // ee    namespace

#endif
