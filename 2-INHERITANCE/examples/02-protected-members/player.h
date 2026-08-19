#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string_view>
#include "person.h"

using namespace std;


class Player : public Person {

    friend ostream& operator << (ostream &out, const Player &player);

    public:
        Player();
        Player(string_view, string_view, string_view);

    private: 
        string m_game;    
};


ostream& operator << (ostream &out, const Player &player) {
    out << "Player: [ game: " << player.m_game << ", names: " 
        << player.get_first_name() << " " << player.get_last_name() << " ]" << endl;

    return out;
}

Player::Player(string_view game_param, string_view first_name_param, string_view last_name_param) 
{
    m_game = game_param;
    first_name = first_name_param;
    last_name = last_name_param;
}


#endif   // PLAYER_H