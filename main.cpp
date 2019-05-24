#include <SFML/Graphics.hpp>
#include "Maze.h"
int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 800), "Maze Game");
    Maze maze;

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        win.clear();
        maze.drawMaze(win);
        win.display();
    }

    return 0;
}

