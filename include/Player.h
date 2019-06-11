#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze.h"
#include "Being.h"
class Player : public Being
{
    public:
        Player(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength);
        virtual ~Player();
        void update();
        //bool recursiveSolve(Maze&, int, int);

    protected:

    private:

};

#endif // PLAYER_H
