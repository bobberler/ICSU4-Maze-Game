#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze.h"
#include "Being.h"
class Player : public Being
{
    public:
        Player(sf::Vector2f);
        virtual ~Player();
        void display (sf::RenderWindow&);
        void update();
        //bool recursiveSolve(Maze&, int, int);

    protected:

    private:

};

#endif // PLAYER_H
