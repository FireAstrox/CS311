// Rylan Clavell
// 2023-11-2
//
// For CS 311 Fall 2023
// Assignment 5
// Header for class TMSArray
#ifndef FILE_TMSARRAY_HPP_INCLUDED
#define FILE_TMSARRAY_HPP_INCLUDED

#include <cstddef>      
// For std::size_t
#include <algorithm>   
// For std::max, std::copy, std::rotate

template <typename T>
class TMSArray {
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = value_type *;
    using const_iterator = const value_type *;

private:
    enum { DEFAULT_CAP = 42 };

public:
    // Default constructor and constructor from size
    explicit TMSArray(size_type thesize = 0)
        : _capacity(std::max(2*thesize, size_type(DEFAULT_CAP))),
          _size(thesize),
          _data(new value_type[_capacity]) {
    }

    // Copy constructor 
    //(Strong Guarantee)
    TMSArray(const TMSArray & other)
        : TMSArray(other._size) {
        try{
        std::copy(other.begin(), other.end(), begin());
        } catch(...){
            throw;
        }
        }
    // Move constructor 
    //(No-Throw Guarantee)
    TMSArray(TMSArray &&other) noexcept
        : _capacity(other._capacity), _size(other._size), _data(other._data) {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment operator 
    //(Strong Guarantee)
    TMSArray &operator=(const TMSArray &other) {
        if (this != &other) {
            TMSArray temp(other);
            swap(temp);
        }
        return *this;
    }

    // Move assignment operator 
    //(No-Throw Guarantee)
    TMSArray &operator=(TMSArray &&other) noexcept {
        if (this != &other) {
            swap(other);
        }
        return *this;
    }

    // Destructor 
    //(No-Throw Guarantee)
    ~TMSArray() noexcept {
        delete[] _data;
    }

    // Element access operator for non-const and const 
    //(No-Throw Guarantee)
    value_type &operator[](size_type index) {
        return _data[index];
    }

    const value_type &operator[](size_type index) const {
        return _data[index];
    }

    // Get the size of the array 
    //(No-Throw Guarantee)
    size_type size() const noexcept {
        return _size;
    }

    // Check if the array is empty (No-Throw Guarantee)
    bool empty() const noexcept {
        return size() == 0;
    }

    // Get an iterator to the beginning of the array 
    //(No-Throw Guarantee)
    iterator begin() noexcept {
        return _data;
    }

    const_iterator begin() const noexcept {
        return _data;
    }

    // Get an iterator to the end of the array 
    //(No-Throw Guarantee)
    iterator end() noexcept {
        return begin() + size();
    }

    const_iterator end() const noexcept {
        return begin() + size();
    }

    // Resize the array to a new size 
    //(Offers Basic Guarantee)
    void resize(size_type newsize) {
        if (newsize <= _capacity) {
            _size = newsize;
        } else {
            TMSArray temp(newsize);
            std::copy(begin(), end(), temp.begin());
            swap(temp);
        }
    }

    // Insert an element at the specified position 
    //(Offers Basic Guarantee)
    iterator insert(iterator pos, const value_type &item) {
        auto offset = pos - begin();
        try {
            resize(_size + 1);

            iterator newend = end() - 1;
            *newend = item;
            std::rotate(begin() + offset, newend, end());
        } catch (...) {
            throw;
        }
        return (begin() + offset);
    }

    // Erase an element at the specified position
    //(Offers Basic Guarantee)
    iterator erase(iterator pos) {
        if (pos == (end() - 1)) {
            try {
                resize(_size - 1);
            } catch (...) {
                throw;
            }
            return end();
        } else {
            try {
                std::rotate(pos, pos + 1, end());
                resize(_size - 1);
            } catch (...) {
                throw;
            }
            return pos;
        }
    }

    // Push an element to the back of the array 
    //(Offers Basic Guarantee)
    void push_back(const value_type &item) {
        insert(end(), item);
    }

    // Pop the last element from the array 
    //(Offers Basic Guarantee)
    void pop_back() {
        erase(end() - 1);
    }

    // Swap the content of two TMSArray objects 
    //(No-Throw Guarantee)
    void swap(TMSArray &other) noexcept {
        std::swap(_size, other._size);
        std::swap(_data, other._data);
        std::swap(_capacity, other._capacity);
    }

private:
    size_type _capacity;
    size_type _size;
    value_type *_data;
};

#endif // FILE_TMSARRAY_HPP_INCLUDED