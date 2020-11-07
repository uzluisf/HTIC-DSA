/*
 * Utils.hpp
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

template<typename T>
T max(T a, T b) {
    return (a >= b) ? a : b;
}


// Function object that returns an integral type for an object of a certain type.
template<typename K>
class hashCode {
public:
  size_t operator()(const K& k);
};

// Default hashCode for std::string
template<>
class hashCode<std::string> {
public:
  size_t operator()(const std::string k) {
    size_t hashVal = 0;
    for (auto ch : k) hashVal = 37 * hashVal + ch;
    return hashVal;
  }
};


#endif /* UTILS_HPP_ */
