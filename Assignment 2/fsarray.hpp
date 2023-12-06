/*Rylan Clavell
CS 311
Assignment 2
fsarray.hpp
Header file for fsarray_test.cpp
*/

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

#include <stdexcept>
#include <cstddef>
#include <algorithm>  // For std::equal

template <typename T>
class FSArray {
public:
    using value_type = T;
    using size_type = std::size_t;

     // Constructor with size
    FSArray(size_type size) : size_(size), data_(new T[size_]) {}

    // Constructor with size and initial value
    FSArray(size_type size, const value_type & t) : size_(size){
        data_ = new T[size_];

        for (size_type i = 0; i < size_; ++i){
            data_[i] = t;
        }
    }

public: //BIG 5 

    // Default constructor
    FSArray() : size_(8) {
        data_ = new T[size_]();
    }

    // Destructor
    ~FSArray() {
        delete[] data_;
    }

    // Copy constructor
    FSArray(const FSArray& other) : size_(other.size_) {
        data_ = new T[size_];
        std::copy(other.begin(), other.end(), data_);
    }

    // Move constructor
    FSArray(FSArray&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    
    //Copy assignment
        FSArray & operator=(const FSArray & other){
            FSArray<T> temp(other);
            mswap(temp);
            return *this; 
        }

    // Move assignment
    FSArray& operator=(FSArray&& other) noexcept {
         mswap(other);
            return *this;
        }
    
public: 

    //Swapper
        void mswap(FSArray & other) noexcept {
            std::swap(size_, other.size_);
            std::swap(data_, other.data_);
        } 

    // Bracket operator for element access
    T& operator[](size_type index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    // Const version of the bracket operator
    const T& operator[](size_type index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    // Member function to get the size of the array
    size_type size() const {
        return size_;
    }

    // Member function to get a pointer to the beginning of the array
    T* begin() {
        return data_;
    }

    // Member function to get a pointer to the end of the array
    T* end() {
        return data_ + size_;
    }

    // Const version of begin() for const objects
    const T* begin() const {
        return data_;
    }

    // Const version of end() for const objects
    const T* end() const {
        return data_ + size_;
    }

    // Comparison Operators
    bool operator==(const FSArray<T>& other) const {
        if (size_ != other.size_) {
            return false;
        }
        return std::equal(begin(), end(), other.begin());
    }

    bool operator!=(const FSArray<T>& other) const {
        return !(*this == other);
    }

    bool operator<(const FSArray<T>& other) const {
        for(size_type i = 0; i < size_ && i < other.size_; ++i){
           if(data_[i] < other.data_[i]){                        
                    return true;
                }
                else if (other.data_[i] < data_[i]){                  
                    return false;
                }
            }
            if(size_ < other.size_){                                  
                return true;
            }
            return false;
        }
    

    bool operator<=(const FSArray<T>& other) const {
        return !(other < *this);
    }

    bool operator>(const FSArray<T>& other) const {
        return other < *this;
    }

    bool operator>=(const FSArray<T>& other) const {
        return !(*this < other);
    }

private:
    size_type size_;
    T* data_;

};

#endif
