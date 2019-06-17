#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Maze.h"
#include "Player.h"
#include "Monster.h"
#include "Image.h"
#include "Hint.h"
#define HEIGHT 800
#define WIDTH 800

class Monster;

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
        static sf::Vector2i mousePos;

        static Monster* getMonsterWithLocation(Point);

    protected:

    private:
        sf::RenderWindow window;
        static Monster* monster1;
        static Monster* monster2;
        static Monster* monster3;
        static Monster* monster4;
};

#endif // GAME_H
