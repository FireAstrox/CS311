// da3.hpp
// Rylan Clavell
// 2023-09-21
//
// For CS 311 Fall 2023
// Header for Assignment 3 functions

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range
#include <algorithm>   // For std::is_sorted

// Function to look up a value in a linked list at a given index.
// Throws std::out_of_range if the list is empty or the index is out of range.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index) {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }

    const LLNode<ValueType> *current = head;
    std::size_t count = 0;

    while (current != nullptr && count < index) {
        current = current->_next;
        count++;
    }

    if (current == nullptr) {
        throw std::out_of_range("Index out of range");
    }

    return current->_data;
}

// Function that checks if a given function object throws an exception and sets the "threw" flag accordingly.
// Implementation in source file
void didItThrow(const std::function<void()> & ff, bool & threw);

// Function to check if a range defined by forward iterators is sorted.
// Returns true if the range is sorted; otherwise, returns false.
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    return std::is_sorted(first, last);
}

// Function to calculate the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
// Implementation in source file
int gcd(int a, int b);

#endif  //#ifndef FILE_DA3_HPP_INCLUDED
