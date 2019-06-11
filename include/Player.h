#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.h"
#include "Image.h"
class Player : public Being
{
    public:
        Player(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength);
        virtual ~Player();
        void update();
        bool getKey();

    protected:

    private:
        bool key;
        Image* hearts[10];

};

#endif // PLAYER_H
