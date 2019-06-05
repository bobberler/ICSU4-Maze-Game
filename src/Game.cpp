#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode(HEIGHT, WIDTH), "Maze Game", sf::Style::Default);
    window.setFramerateLimit(60);
    maze = new Maze();
    player = new Player(maze->getCellPosition(1,1));
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
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
        update();
        draw();
    }
}

void Game::update()
{
    player->update();
    return;
}

void Game::draw()
{
    window.clear();
    maze->drawMaze(window);
    player->display(window);
    window.display();
    return;
}
