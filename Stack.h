/* File: Stack.h
 * Name: Paulo Lemus
 * Date: 4/2/2017
 */

#ifndef EE_STACK_LIST_H_
#define EE_STACK_LIST_H_

#include <stdexcept>
// #include <exception>
#include <iostream>

namespace ee {
namespace list {

template <typename T>
struct node {
    T data;
    node* next;

    node(const T& data);
};

template <typename T>
class Stack {

    node<T>* top;
    int sz;
    int cap;

    public:
    Stack(int capacity);
    int  size();
    int  capacity();
    bool isEmpty();
    bool isFull();
    bool push(const T& data);
    T    pop();
    T    peek();
    void print();
};

////////////////////////////////////
//       Implementations          //
////////////////////////////////////

template <typename T>
node<T>::node(const T& data) : data(data), next(nullptr) {}

template <typename T>
Stack<T>::Stack(int capacity) : top(nullptr), sz(0), cap(capacity) {}
template <typename T>
int Stack<T>::size() { return sz; }
template <typename T>
int Stack<T>::capacity() { return cap; }
template <typename T>
bool Stack<T>::isEmpty() { return (sz <= 0); }
template <typename T>
bool Stack<T>::isFull() { return (sz >= cap); }

template <typename T>
bool Stack<T>::push(const T& data) {
    if(sz < cap) {
        if(top == nullptr) {
            top = new node<T>(data);
        }
        else {
            node<T>* ptr = new node<T>(data);
            ptr->next = top;
            top = ptr;
        }
        sz++;
        return true;
    }
    else return false;
}
template <typename T>
T Stack<T>::pop() {
    if(sz > 0) {
        node<T>* ptr = top;
        T data = top->data;
        top = top->next;
        sz--;
        delete ptr;
        return data;
    }
    else throw std::runtime_error("Popped from empty stack");
}

template <typename T>
T Stack<T>::peek() {
    if(sz > 0) {
        return top->data;
    }
    else throw std::runtime_error("Peeked on empty stack");
}

template <typename T>
void Stack<T>::print() {
    node<T>* ptr = top;
    std::cout << "Stack Contents:" << std::endl;
    while(ptr) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

} // list namespace
} // ee namespace

#endif
