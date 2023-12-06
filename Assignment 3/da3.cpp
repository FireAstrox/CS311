// da3.cpp
// Rylan Clavell
// 2023-09-21
//
// For CS 311 Fall 2023
// Source for Assignment 3 functions

#include "da3.hpp"     // For Assignment 3 prototypes & templates
#include <functional>  // For std::function

using std::function;

// Function that checks if a given function object throws an exception
// and sets the "threw" flag
void didItThrow(const std::function<void()> & ff, bool & threw)
{
    threw = false;
    try {
        ff();
    } catch (...) {
        threw = true;
        throw; // Re-throw the caught exception
    } 
}

// Function to calculate the greatest common divisor (GCD) of two integers using Euclidean algorithm.
int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
