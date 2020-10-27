/*
 * ArrayStack.hpp
 */

#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_
#include <stdexcept> // for exceptions
#include "Array.hpp"
#include "Utils.hpp"

template<typename T>
class ArrayStack {
public:
	// LIFECYCLE
	ArrayStack();
	ArrayStack(T x);
	~ArrayStack();

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
	Array<T> arr; // 0-indexed array of elements
	int n;        // number of elements in array

	void resize() {
		Array<T> b{ max(2 * arr.size(), 1) };
		for (int i = 0; i < arr.size(); i++)
			b[i] = arr[i];
		arr = b;
	}
};

template<typename T>
ArrayStack<T>::ArrayStack() : arr{1} {
	n = 0;
}

template<typename T>
ArrayStack<T>::ArrayStack(T x) : arr{1}, n{0} {
	push(x);
}

template<typename T>
ArrayStack<T>::~ArrayStack() {}

template<typename T>
void ArrayStack<T>::push(T x) {
	// If the number of elements is greater than the array's size, then
	// resize the array. Notice that we use n as the index for the element
	// soon-to-be-inserted before incrementing n.
	if (n + 1 > arr.size()) resize();
	arr[n] = x;
	n += 1;
}

template<typename T>
T ArrayStack<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("Stack underflow: cannot remove from empty stack.");
	}
	else {
		T topItem = arr[n - 1];
		n -= 1;
		return topItem;
	}
}

template<typename T>
T ArrayStack<T>::peek() {
	if (isEmpty()) {
		throw std::logic_error("Stack underflow: cannot peek empty stack.");
	}
	else {
		return arr[n - 1];
	}
}
#endif /* ARRAYSTACK_HPP_ */
