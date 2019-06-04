#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze.h"

class Player
{
    public:
        Player(sf::Vector2f);
        virtual ~Player();
        void display (sf::RenderWindow&);
        void update();
        //bool recursiveSolve(Maze&, int, int);

    protected:

    private:
        sf::RectangleShape body;
        sf::Vector2f position;
        int mazeX;
        int mazeY;
        bool autoSolver;
        Maze maze;
};

#endif // PLAYER_H
