/*Rylan Clavell
CS 311
Assignment 1
player.cpp
*/

#include <iostream>
#include "player.hpp"
#include <cassert> 

//Constructors
Player::Player() : realName("UNKNOWN"), username("UNKNOWN"), games(0) {
    assert(realName == "UNKNOWN");
    assert(username == "UNKNOWN");
    assert(games == 0);
}

Player::Player(const std::string &realName, const std::string &username, int games)
    : realName(realName), username(username), games(games) {
     assert(games >= 0);
    }
 
 // get and set functions

 std::string Player::getRealName() const{
    return realName;
 }   

 void Player::setRealName(const std::string &realName) {
    assert(!realName.empty()); //Check realName is not empty
    this->realName = realName;
 }

std::string Player::getUsername() const {
    return username;
}

void Player::setUsername(const std::string &username) {
   assert(!username.empty()); // Check that Username is not empty
    this->username = username;
}

int Player::getGames() const {
    return games;
}

void Player::setGames(int games) {
   assert(games >= 0); // Check that Games is non-negative
    this->games = games;
}
// Member functions
bool Player::inactive() const {
    return games == 0;
}

std::string Player::toString() const {
   assert(!realName.empty());
   assert(!username.empty());
    return realName + " (" + username + "): " + std::to_string(games);
}

// Operators
bool Player::operator==(const Player& other) const {
    return (realName == other.realName) && (username == other.username) && (games == other.games);
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

Player& Player::operator++() {
    // Pre-increment
      assert(games >= 0); // Check that Games is non-negative before incrementing
        ++games;
   
    return *this;
}

Player Player::operator++(int) {
    // Post-increment
    Player temp(*this);
    ++(*this);
    return temp;
}

Player& Player::operator--() {
    // Pre-decrement
    assert(this->games >= 0); // Check that Games is positive before decrementing
    if (games > 0) {
        --games;
    }
    return *this;
}

Player Player::operator--(int) {
    // Post-decrement
    Player temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.toString();
    return os;
}