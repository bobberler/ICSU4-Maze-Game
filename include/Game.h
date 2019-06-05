#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "Player.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void run();
        void update();
        void draw();

    protected:

    private:
        sf::RenderWindow window;
        Player* player;
        Maze* maze;
};

#endif // GAME_H
