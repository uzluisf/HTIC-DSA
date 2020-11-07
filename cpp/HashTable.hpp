#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "Array.hpp"
#include "DoublyLinkedList.hpp"

namespace HashTable {

template<typename T>
class ChainedHashTable {
public: 
    ChainedHashTable() : table{2} {
        n = 0;
    }

    // Return true if item was inserted into table. Otherwise, false.
    bool insert(T x) {
        if (_find(x) != nullptr) return false; // return early if item's in the table
	    if (n + 1 > table.size()) _resize();   // resize if table is full
	    table[hash(x)].addFirst(x);           // insert at the list's head at index head(x)
	    n += 1;
	    return true;
    }
    
    // Return true if item x is in table. Otherwise, return false.
    bool search(T x) const {
        return _find(x) != nullptr ? true : false;
    }

    // Return true if item is removed from table. Otherwise, return false.
    bool remove(T x) {
        return _remove(x) != nullptr ? true : false;
    }

    // Return number of elements..
    inline int size() const { return n; }

    // Return the the whole number resulting from hash(x) mod table.size().
	int hash(T x) {
		hashCode<T> getHashCode;
        return getHashCode(x) % table.size();
	}

    friend std::ostream& operator<<(std::ostream& out, ChainedHashTable& t) {
       for (int i = 0; i < t.table.size(); i++) {
           if (t.table[i].elems() != 0) {
                printf("%-05d | ", i);
                out << t.table[i];
           }
           else {
               printf("%-05d |\n", i);
           }
       }
       return out;
    }

private:
    Array<DoublyLinkedList<T>> table; // Each array slot is a list
    int n;                            // Number of elements in all lists
    
    void _resize() {
	    int d = 1;
	    while (1<<d <= n) d++;
	    Array<DoublyLinkedList<T>> newTable{1<<d};
	    for (int i = 0; i < table.size(); i++) {
		    for (int j = 0; j < table[i].elems(); j++) {
			    T x = table[i].getAt(j);
			    newTable[hash(x)].addFirst(x);
            }
		}
	    table = newTable;
    }

    T* _find(T x) {
        int j = hash(x);
        for (int i = 0; i < table[j].elems(); i++) {
            if (x == table[j].getAt(i)) return new T(table[j].getAt(i));
        }
        return nullptr;
    }

    T* _remove(T x) {
        int j = hash(x);
        for (int i = 0; i < table[j].elems(); i++) {
            T y = table[j].getAt(i);
            if (x == y) {
                table[j].removeAt(i);
                n -= 1;
                return new T(y);
            }
        }
        return nullptr;
    }
};

};

#endif