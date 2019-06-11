#include "Player.h"
#include "Game.h"

Player::Player(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength) : Being(_position, _layer, _label, _hp, _strength)
{
    texture.loadFromFile("assets/player.png");
    sprite.setTexture(texture);
    key = false;
    for(int x = 0; x < 10; x++)
        hearts[x] = new Image(sf::Vector2f(40*x, 0), 1, "assets/heart.png", "heart");

    //ctor
}

Player::~Player()
{
    //dtor
}

bool Player::getKey()
{
    return key;
}

void Player::update()
{
    if(Game::direction == 'U' and Maze::maze[mazePos.y-1][mazePos.x] % 2 == 0)
    {
        mazePos.y--;
    }
    else if (Game::direction == 'L' and Maze::maze[mazePos.y][mazePos.x-1] % 2 == 0)
    {
        mazePos.x--;
    }
    else if (Game::direction == 'D' and Maze::maze[mazePos.y+1][mazePos.x] % 2 == 0)
    {
        mazePos.y++;
    }
    else if (Game::direction == 'R' and Maze::maze[mazePos.y][mazePos.x+1] % 2 == 0)
    {
        mazePos.x++;
    }
    Game::direction = ' ';
    Being::update();
    if(Maze::maze[mazePos.y][mazePos.x] == 4)
    {
        key = true;
    }
//    mazeX = (position.x)*20/WIDTH;//calculates the cell in the maze its in
//    mazeY = (position.y)*20/HEIGHT;
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        if (maze.getColor(mazeX, mazeY-1) == sf::Color::White)
//            position.y = maze.getCellPosition(mazeX, mazeY-1).y;
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        if (maze.getColor(mazeX, mazeY+1) == sf::Color::White)
//            position.y = maze.getCellPosition(mazeX, mazeY+1).y;
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        if (maze.getColor(mazeX+1, mazeY) == sf::Color::White)
//            position.x = maze.getCellPosition(mazeX+1, mazeY).x;
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        if (maze.getColor(mazeX-1, mazeY) == sf::Color::White)
//            position.x = maze.getCellPosition(mazeX-1, mazeY).x;
//    }
//
//    body.setPosition(position);
//    sf::sleep(sf::milliseconds(50));
    //std::cout << "x: " << mazeX << " y: " << mazeY << std::endl;
    //std::cout << "x: " << position.x+10 << " y: " << position.y+10 << std::endl;
    return;
}
