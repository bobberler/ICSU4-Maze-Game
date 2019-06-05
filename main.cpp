#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "Player.h"
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Maze Game", sf::Style::Default, settings);
    Maze maze;
    Player player(maze.getCellPosition(1,1));
    window.setFramerateLimit(60) ;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        player.update();
        window.clear();
        maze.drawMaze(window);
        player.display(window);
        window.display();
    }

    return 0;
}

