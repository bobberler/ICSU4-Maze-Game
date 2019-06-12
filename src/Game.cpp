#include "Game.h"

LinkedList* GameObject::objects;
char Game::direction;

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
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            if(Maze::maze[y][x] == 1)
                Image* wall = new Image(sf::Vector2f(40*x, 40*y), 1, "assets/wall.png", "wall");
            if(Maze::maze[y][x] == 2)
                Image* end = new Image (sf::Vector2f(40*x, 40*y), 1, "assets/star.png", "end");
            if(Maze::maze[y][x] == 4)
                key = new Image (sf::Vector2f(40*x, 40*y), 1, "assets/key.png", "key");
            if(Maze::maze[y][x] == 3)
                door = new Image (sf::Vector2f(40*x, 40*y), 1, "assets/door.png", "door");
        }
    }
    monster = new Monster(sf::Vector2f (8*40, 10*40), 1, "monster", 10, 10);
    player = new Player(sf::Vector2f(1*40, 1*40), 1, "player", 10, 10);
    while (window.isOpen())
    {
        input();
        update();
        draw();
    }
}

void Game::input()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == event.KeyPressed)
        {
            if(event.key.code == sf::Keyboard::W or event.key.code == sf::Keyboard::Up)
            {
                direction = 'U';
            }
            else if(event.key.code == sf::Keyboard::A or event.key.code == sf::Keyboard::Left)
            {
                direction = 'L';
            }
            else if (event.key.code == sf::Keyboard::S or event.key.code == sf::Keyboard::Down)
            {
                direction = 'D';
            }
            else if (event.key.code == sf::Keyboard::D or event.key.code == sf::Keyboard::Right)
            {
                direction = 'R';
            }

        }
    }
    return;
}

void Game::update()
{

    for(int i = 0; i < GameObject::objects->getSize(); i++)
    {
        GameObject::objects->getLinkAt(i)->contents->update();
    }
    if (player->getKey())
    {
        delete key;
        delete door;
        Maze::maze[10][13] = 0;
    }
    return;
}

void Game::draw()
{
    window.clear(sf::Color::White);

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
