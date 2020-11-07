#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_
#include <stdexcept>
#include <iostream>

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    void addFirst(T newData) {
        if (head == nullptr) {
            head = tail =  new Node{newData};
        }
        else {
            head->prev = new Node{newData}; // set current head's prev to new node
            head->prev->next = head;        // set new node's next to currrent head
            head = head->prev;              // make current node the head
        }
        size += 1;
    }

    void addLast(T newData) {
        if (head == nullptr) {
            head = tail = new Node{newData};
        }
        else {
            tail->next = new Node{newData};
            tail->next->prev = tail;
            tail = tail->next;
        }
        size += 1;
    }

    T removeFirst() {
        if (isEmpty()) throw std::logic_error("Cannot remove from empty list.");

        T data = head->data;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        else head->prev = nullptr;
        size -= 1;
        return data;
    }
    
    T removeLast() {
        if (isEmpty()) throw std::logic_error("Cannot remove from empty list.");

        T data = tail->data;
        tail = tail->prev;
        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        size -= 1;
        return data;
    }
    
    T getAt(int index) {
        if (index < 0 || index >= size) throw std::logic_error("Index out of range.");
        return _getNode(index)->data;
    }

    T removeAt(int index) {
        if (index < 0 || index >= size) throw std::logic_error("Index out of range.");
        Node* node = _getNode(index);
        return _remove(node);
    }

    T peekFirst() const {
        if (isEmpty()) throw std::logic_error("Empty list.");
        return head->data; 
    }
    T peekLast() const {
        if (isEmpty()) throw std::logic_error("Empty list.");
        return tail->data; 
    }
    
    int indexOf(T val) const {
        int index = 0;
        for (Node* curr = head; curr != nullptr; curr = curr->next, index++) {
            if (curr->data == val) return index;
        }
        return -1;
    }

    bool contains(T val) const { return indexOf(val) != -1; }
    int elems() const { return size; }
    bool isEmpty() const { return size == 0; }
    
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list) {
        for (Node* curr = list.head; curr != nullptr; curr = curr->next) {
            if (curr->next) out << curr->data << " -> ";
            else out << curr->data << "\n";
        }
        return out;
    }

private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T newData) : data{newData}, prev{nullptr}, next{nullptr} {}
    };

    Node* head;
    Node* tail;
    int size;

    Node* _getNode(int index) {
        Node* curr = nullptr;
        if (index < size/2) {
            curr = head;
            for (int i = 0; i != index; i++) {
                curr = curr->next;
            }
        }
        else {
            curr  = tail;
            for (int i = size-1; i != index; i--) {
                curr = curr->prev;
            }
        }
        return curr;
    }

    T _remove(Node*& curr) {
        if (curr->prev == nullptr) return removeFirst();
        if (curr->next == nullptr) return removeLast();

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        T data = curr->data;
        delete curr;
        size -= 1;

        return data;      
    }
};

#endif