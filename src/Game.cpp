#include "Game.h"
#include <string>
LinkedList* GameObject::objects;//declare statics
char Game::direction;
Monster* Game::monster1;
Monster* Game::monster2;
Monster* Game::monster3;
Monster* Game::monster4;
sf::Vector2i Game::mousePos;

Game::Game()
{
    window.create(sf::VideoMode(HEIGHT, WIDTH), "Maze Game", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    GameObject::objects = new LinkedList();//initialize linked list of gameobjects
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    Maze maze;
    for(int y = 0; y < 20; y++)//create all game objects
    {
        for(int x = 0; x < 20; x++)
        {
            if(Maze::maze[y][x] == 1)
                Image* wall = new Image(sf::Vector2f(40*x, 40*y), "assets/wall.png", "wall");
            if(Maze::maze[y][x] == 2)
                Image* end = new Image (sf::Vector2f(40*x, 40*y), "assets/star.png", "end");
            if(Maze::maze[y][x] == 4)
                Image* key = new Image (sf::Vector2f(40*x, 40*y), "assets/key.png", "key");
            if(Maze::maze[y][x] == 3)
                Image* door = new Image (sf::Vector2f(40*x, 40*y), "assets/door.png", "door");
            if(Maze::maze[y][x] == 6)
                Image* healthpack = new Image (sf::Vector2f(40*x, 40*y), "assets/healthpack.png", "healthpack"+std::to_string(x)+std::to_string(y));
        }
    }
    monster1 = new Monster(sf::Vector2f(1*40, 9*40), "monster1", 5, 1);
    monster2 = new Monster(sf::Vector2f(11*40, 7*40), "monster2", 3, 2);
    monster3 = new Monster(sf::Vector2f(12*40, 13*40), "monster3", 7, 1);
    monster4 = new Monster(sf::Vector2f(18*40, 13*40), "monster4", 4, 1);
    Player* player = new Player(sf::Vector2f(1*40, 1*40), "player", 10, 1);
    Hint* hint = new Hint(sf::Vector2f(19*40, 0), "hint");
    while (window.isOpen())
    {
        input();
        update();
        draw();
        if(Player::getDead() == true) //end if dead
        {
            sf::sleep(sf::seconds(2));
            window.close();
            return;
        }
        if(Player::getWon() == true) //end if won
        {
            sf::sleep(sf::seconds(2));
            window.close();
            return;
        }
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
            if(event.key.code == sf::Keyboard::W or event.key.code == sf::Keyboard::Up) //set keyboard input to a variable
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
    mousePos = sf::Mouse::getPosition(window); //set mouse pos to variable
    return;
}

void Game::update()
{

    for(int i = 0; i < GameObject::objects->getSize(); i++)
    {
        GameObject::objects->getLinkAt(i)->contents->update(); //update all gameObjects (some dont do anything)
    }
    return;
}

void Game::draw()
{
    window.clear(sf::Color::White);

    for(int i = 0; i < GameObject::objects->getSize(); i++)
    {
            GameObject::objects->getLinkAt(i)->contents->updatePosition(); //update pos
            window.draw(GameObject::objects->getLinkAt(i)->contents->getSprite());//draw
            //GameObject::objects->getLinkAt(i)->contents->draw(window);
    }

    window.display();
    return;
}

Monster* Game::getMonsterWithLocation(Point _location) //return monster based on location given
{
    if(monster1->getMazePos().x == _location.x and monster1->getMazePos().y == _location.y)
        return monster1;
    if(monster2->getMazePos().x == _location.x and monster2->getMazePos().y == _location.y)
        return monster2;
    if(monster3->getMazePos().x == _location.x and monster3->getMazePos().y == _location.y)
        return monster3;
    if(monster4->getMazePos().x == _location.x and monster4->getMazePos().y == _location.y)
        return monster4;
    return NULL;
}
