#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "person.h"

using namespace std;

//  Player will do public inheritance from Person
class Player : public Person
{
    friend ostream& operator << (ostream& out, const Player& player);

    public:
        Player();
        ~Player();
        
        //See the access we have to inherited members from Person
        void play() {

            m_full_name = "John Snow";   // OK
            m_age = 55;   // OK

            // m_address = "Uwork"; [Compiler error]
        }

    private: 
        int m_career_start_year;
        double m_salary;
        int health_factor;
};

Player::Player()
{
    m_career_start_year = 0;
    m_salary = 0.0;
    health_factor = 0;
}

ostream& operator << (ostream& out, const Player& player){
    out << "Player [Full name: " << player.get_full_name() <<
                    ",age: " << player.get_age() << 
                    ",address: " << player.get_address() << "]";
    return out;
}


Player::~Player()
{
}

#endif // PLAYER_H
