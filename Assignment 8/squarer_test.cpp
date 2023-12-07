// squarer_test.cpp  SKELETON
// Glenn G. Chappell
// 2023-11-28
//
// For CS 311 Fall 2023
// Test program for class Squarer
// For Assignment 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.hpp

// Includes for code to be tested
#include "squarer.hpp"       // For class Squarer

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework


// *********************************************************************
// Test Cases
// *********************************************************************
// Test Squarer with integer input
TEST_CASE("Squarer with integer") {
    Squarer sq;
    int arg = 7;
    int expected = 49;
    INFO("Testing with integer: " << arg << "; Expected square: " << expected);
    REQUIRE(sq(arg) == expected);
}

// Test Squarer with negative integer input
TEST_CASE("Squarer with negative integer") {
    Squarer sq;
    int arg = -3;
    int expected = 9;
    INFO("Testing with negative integer: " << arg << "; Expected square: " << expected);
    REQUIRE(sq(arg) == expected);
}

// Test Squarer with zero
TEST_CASE("Squarer with zero") {
    Squarer sq;
    int arg = 0;
    int expected = 0;
    INFO("Testing with zero; Expected square: " << expected);
    REQUIRE(sq(arg) == expected);
}

// Test Squarer with floating-point input
TEST_CASE("Squarer with floating-point") {
    Squarer sq;
    double arg = 1.5;
    double expected = 2.25;
    INFO("Testing with floating-point: " << arg << "; Expected square: " << expected);
    REQUIRE(sq(arg) == doctest::Approx(expected));
}

// Test Squarer with large integer
TEST_CASE("Squarer with large integer") {
    Squarer sq;
    long long arg = 10000;
    long long expected = 100000000;
    INFO("Testing with large integer: " << arg << "; Expected square: " << expected);
    REQUIRE(sq(arg) == expected);
}

// Test const Squarer object
TEST_CASE("Const Squarer object") {
    const Squarer constSq;
    int arg = 4;
    int expected = 16;
    INFO("Testing with const Squarer object: " << arg << "; Expected square: " << expected);
    REQUIRE(constSq(arg) == expected);
}