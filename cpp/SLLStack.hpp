/*
 * SLLStack.hpp
 */

#ifndef SLLSTACK_HPP_
#define SLLSTACK_HPP_
#include <stdexcept>


template<typename T>
class SLLStack {
public:
	// LIFECYCLE
	SLLStack();
	SLLStack(T x);
	~SLLStack();

	// OPERATIONS
	void push(T x);
	T pop();

	// OPERATORS

	// ACCESS
	inline int elems() const { return n; }

	// INQUIRY
	inline bool isEmpty() const { return n == 0; }
	T peek();

private:
	struct Node {
		T data;
		Node* next;

		Node(T x) : data{x}, next{nullptr} {}
	};

	Node* head; // stack's top
	int n;      // number of elements in the stack
};

template<typename T>
SLLStack<T>::SLLStack() : head{nullptr}, n{0} { }


template<typename T>
SLLStack<T>::SLLStack(T x) : head{nullptr}, n{0} {
	push(x);

}

template<typename T>
SLLStack<T>::~SLLStack() {
	while (head) {
		Node* curr = head;
		head = head->next;
		delete curr;
	}
}

template<typename T>
void SLLStack<T>::push(T x) {
	if (head == nullptr) {
		head = new Node{x};
	}
	else {
		Node* temp = head;
		head = new Node{x};
		head->next = temp;
	}
	n += 1;
}

template<typename T>
T SLLStack<T>::pop() {
	if (head == nullptr) {
		throw std::logic_error("Stack underflow: cannot remove from empty stack.");
	}
	else {
		T topItem  = head->data;
		Node* temp = head;
		head       = head->next;
		n -= 1;
		delete temp;
		return topItem;
	}
}

template<typename T>
T SLLStack<T>::peek() {
	if (head) {
		return head->data;
	}
	else {
		throw std::logic_error("Stack underflow: cannot peek empty stack.");
	}
}

#endif /* SLLSTACK_HPP_ */
