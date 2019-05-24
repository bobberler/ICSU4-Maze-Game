#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Maze.h"

#define HEIGHT 800
#define WIDTH 800

class Game
{
    public:
        Game();
        virtual ~Game();

        void input();
        void update();
        void draw();

    protected:

    private:
        Maze* maze;
};

#endif // GAME_H
