#ifndef STACK_H
#define STACK_H
#include "DoublyLinkedList.hpp"

template<typename T>
class Stack {
public:
    Stack() : s{} {}
    Stack(T val) {
        s.addLast(val);
    }
    
    void push(T val) {
        s.addLast(val);
    }
    
    T pop() {
        return s.removeLast();
    }

    int elems() { return s.elems(); }
    bool isEmpty() { return s.isEmpty(); }
    
private:
    DoublyLinkedList<T> s;
};

#endif