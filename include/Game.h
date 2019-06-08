#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Maze.h"
#define HEIGHT 800
#define WIDTH 800
#define LAYERS 4
class Game
{
    public:
        Game();
        virtual ~Game();
        void run();
        void input();
        void update();
        void draw();

    protected:

    private:
        sf::RenderWindow window;
};

#endif // GAME_H
