#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string_view>
#include "person.h"

using namespace std;


class Player : public Person {

    // This is output stream operator and it is not the member function of the given class
    // It is a global free standing function
    friend ostream& operator << (ostream &out, const Player &player);

    public:
        Player();

        /*
            If you want to work with words and modify them, use string. 
            If you only want to look at words without modifying them, use string_view.

            `string_view` provides a lightweight, read-only view of a string's data without copying, 
            making it memory-efficient and suitable for avoiding unnecessary allocations or copying
        */
        Player(string_view game_param);

    private: 
        string m_game;    
};


ostream& operator << (ostream &out, const Player &player) {
    out << "Player: [ game: " << player.m_game << ", names: " 
        << player.get_first_name() << " " << player.get_last_name() << " ]" << endl;

    return out;
}

Player::Player(string_view game_param) : m_game(game_param)
{
    /*
        Notice we can not get access to the private elements of the base class (Person)
        and we can't access them from the derived class.

        Compile Error:

        first_name = "John";
        last_name  = "Doe";
    */
}


#endif   // PLAYER_H