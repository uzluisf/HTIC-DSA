#ifndef QUEUE_H
#define QUEUE_H
#include "DoublyLinkedList.hpp"

template<typename T>
class Queue {
public:
    Queue() : q{} {}
    Queue(T val) {
        q.addLast(val);
    }
    
    void enqueue(T val) {
        q.addLast(val);
    }
    
    T dequeue() {
        return q.removeFirst();
    }

    int elems() { return q.elems(); }
    bool isEmpty() { return q.isEmpty(); }
    
private:
    DoublyLinkedList<T> q;
};

#endif