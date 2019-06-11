#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Maze.h"
#include "Player.h"
#include "Monster.h"
#include "Image.h"
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
        static char direction;

    protected:

    private:
        sf::RenderWindow window;
        Player* player;
        Monster* monster;
        Image* key;
        Image* door;
        Image* hearts[10];
};

#endif // GAME_H
