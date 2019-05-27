#ifndef MAZE_H
#define MAZE_H

#define MAZE_HEIGHT 20
#define MAZE_WIDTH 20
#define HEIGHT 800
#define WIDTH 800
#define STARTX 1
#define STARTY 1
#define ENDX 19
#define ENDY 19

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <fstream>

class Maze
{
    public:
        Maze();
        virtual ~Maze();
        void drawMaze (sf::RenderWindow&);

        sf::Vector2f getCellPosition(int, int);
        sf::Vector2f getSize (int, int);
        sf::Color getColor (int, int);
        void setColor (int, int, sf::Color)

    protected:

    private:
        sf::RectangleShape cell[MAZE_HEIGHT][MAZE_WIDTH];

};

#endif // MAZE_H
