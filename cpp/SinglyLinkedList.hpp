#ifndef SINGLYLINKEDLIST_HPP_
#define SINGLYLINKEDLIST_HPP_
#include <stdexcept>

template<typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() {
        head = tail = nullptr;
        n = 0;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* curr = head;
            head = head->next;
            delete curr;
        }
    }

    // Add an element to the linked list's head.
    void addFirst(T newData) {
        Node* newNode = new Node{newData};
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        n += 1;
    }

    // Add an element to the linked list's tail.
    void addLast(T newData) {
        Node* newNode = new Node{newData};
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        n += 1;
    }

    // Remove the first value at the linked list's head.
    T removeFirst() {
        if (isEmpty()) {
            throw std::logic_error("Cannot remove from empty list.");
        }

        T data = head->data;
        Node* nodeToDelete = head;
        n -= 1;
        head = head->next;
        if (isEmpty()) tail = nullptr;
        delete nodeToDelete;
        return data;
    }

    // Remove the last value at the linked list's tail.
    T removeLast() {
        if (isEmpty()) {
            throw std::logic_error("Cannot remove from empty list.");
        }

        T data;
        if (head->next == nullptr) {
            data = head->data;
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* secondToLast = head;
            while (secondToLast->next->next != nullptr) {
                secondToLast = secondToLast->next;
            }
            data = secondToLast->next->data;
            delete secondToLast->next;
            secondToLast->next = nullptr;
            tail = secondToLast;
        }
        n -= 1;
        return data;
    }

    // Remove element at given index.
    T removeAt(int index) {
        if (index < 0 || index >= size()) {
            throw std::logic_error("Index out of range.");
        }

        // If the node is at either at the head or the tail,
        // handle it independently
        if (index == 0)          return removeFirst();
        if (index == size() - 1) return removeLast();

        // node is between the head and the tail (exclusive)
        Node* pred = nullptr;
        Node* curr = head;
        for (int i = 0; i != index; i++) {
            pred = curr;
            curr = curr->next;
        }

        T data = curr->data;
        pred->next = curr->next;
        n -= 1;
        delete curr;
        return data;
    }

    // Return the element at the linked list's head.
    T peekFirst() const {
        if (isEmpty()) {
            throw std::logic_error("Cannot peek into empty list.");
        }
        return head->data;   
    }

    // Return the element at the linked list's tail.
    T peekLast() const {
        if (isEmpty()) {
            throw std::logic_error("Cannot peek into empty list.");
        }
        return tail->data;   
    }

    // Find the index of the first instance of a particular value. Return -1
    // if not found.
    int indexOf(T val) const {
        int index = 0;
        for (Node* curr = head; curr != nullptr; curr = curr->next, index++) {
            if (curr->data == val) return index;
        }
        return -1;
    }

    // Return true if list contains value. False otherwise.
    bool contains(T val) const {
        return indexOf(val) != -1;
    }

    // Return the size of the linked list (i.e., number of elements in it).
    int size() const {
        return n;
    }

    // Return true if linked list is empty. Otherwise, false.
    bool isEmpty() const {
        return head == nullptr;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(T newData) : data{newData}, next{nullptr} {}
    };

    Node* head;
    Node* tail;
    int n;
};

#endif
