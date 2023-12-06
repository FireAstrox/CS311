/*Rylan Clavell
CS 311
Assignment 1
player.hpp 
Implements player class used in player.cpp
*/

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
#include <string>

class Player{
public:
    //constructors
    Player(); //default constructor
    Player(const std::string &realName, const std::string &username, int games);

    //Get and Set functions
    std::string getRealName() const;
    void setRealName(const std::string &realName);

    std::string getUsername() const;
    void setUsername(const std::string &username);

    int getGames() const;
    void setGames(int games);

    //Member functions
    bool inactive() const;
    std::string toString () const;

    //Operators
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    Player& operator++(); //Pre-increment
    Player operator++(int); //Post-increment
    Player& operator--(); //Pre-decrement
    Player operator--(int); //Post-decrement

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

private:
    std::string realName;
    std::string username;
    int games;
};


#endif