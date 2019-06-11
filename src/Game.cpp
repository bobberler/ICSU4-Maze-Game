#include "Game.h"

LinkedList* GameObject::objects;

Game::Game()
{
    window.create(sf::VideoMode(HEIGHT, WIDTH), "Maze Game", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    GameObject::objects = new LinkedList();
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    Maze maze;
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

    for(int i = 0; i < GameObject::objects->getSize(); i++)
    {
        GameObject::objects->getLinkAt(i)->contents->update();
    }
    return;
}

void Game::draw()
{
    window.clear(sf::Color(210, 186, 252, 255));

    //for(int layer = 0; layer < LAYERS; layer++)
    //{
        for(int i = 0; i < GameObject::objects->getSize(); i++)
        {
            //if(GameObject::objects->getLinkAt(i)->contents->getLayer() == i)
            //{
                GameObject::objects->getLinkAt(i)->contents->updatePosition();
                window.draw(GameObject::objects->getLinkAt(i)->contents->getSprite());
                //GameObject::objects->getLinkAt(i)->contents->draw(window);
            //}
        }
    //}

    window.display();
    return;
}
