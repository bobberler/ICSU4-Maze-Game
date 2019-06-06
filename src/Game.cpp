#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode(HEIGHT, WIDTH), "Maze Game", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
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
        input();
        update();
        draw();
    }
}

void Game::input()
{
    return;
}

void Game::update()
{
    return;
}

void Game::draw()
{
    window.clear();



    window.display();
    return;
}
