#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Point.h"
#include "Game.h"

class Game;

class Maze
{
    public:
        Maze();
        virtual ~Maze();

        static int maze[20][20];

    protected:

    private:

};

#endif // MAZE_H
