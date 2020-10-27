/*
 * A slighly modified version of Pat Morin's array class that
 * simulates Java's array implementation.
 *
 * Source code: https://github.com/patmorin/ods/blob/master/cpp/array.h
 */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_
#include <stdlib.h>  // for std::fill
#include <assert.h>  // for assert

template<typename T>
class Array {
public:
	// LIFECYCLE
	Array(int sz);
	Array(int sz, T init);
	~Array();

	// OPERATIONS
	void fill(T x);
	void reverse();
	void swap(int i, int j);
	//static void copyOfRange(Array<T> &a0, int i, int j);

	// OPERATORS
	Array<T>& operator=(Array<T> &b);
	T& operator[](int i);
	T* operator+(int i);

	// ACCESS
	inline int size() const { return length; }

	// INQUIRY

private:
	T* a;                // pointer-to-T
	int length; // how many elements it can hold
};

template<typename T>
Array<T>::Array(int sz) {
	length = sz;
	a = new T[length];
}

template<typename T>
Array<T>::Array(int sz, T init) {
	length = sz;
	a = new T[length];
	for (int i = 0; i < length; i++) {
		a[i] = init;
	}
}

template<typename T>
Array<T>::~Array() {
	if (a != nullptr) delete[] a;
}

template<typename T>
void Array<T>::fill(T x) {
	std::fill(a, a+length, x);
}

template<typename T>
void Array<T>::swap(int i, int j) {
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

template<typename T>
void Array<T>::reverse() {
	for (int i = 0; i < length/2; i++) {
		swap(i, length-i-1);
	}
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> &b) {
	if (a != nullptr) delete[] a;
	a = b.a;
	b.a = nullptr;
	length = b.length;
	return *this;
}

template<typename T>
T& Array<T>::operator[](int i) {
	assert(i >= 0 && i < length);
	return a[i];
}

template<typename T>
T* Array<T>::operator+(int i) {
	return &a[i];
}

#endif /* ARRAY_HPP_ */
