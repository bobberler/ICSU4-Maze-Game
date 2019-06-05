#include "Player.h"


Player::Player(sf::Vector2f startPosition)
{
    Being::setTexture("../assets/player.png");
    position = startPosition;
    body.setPosition(position);
    int hp = 100;
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::display (sf::RenderWindow& window)
{
    window.draw(body);
}


void Player::update()
{
    mazeX = (position.x)*20/WIDTH;//calculates the cell in the maze its in
    mazeY = (position.y)*20/HEIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (maze.getColor(mazeX, mazeY-1) == sf::Color::White)
            position.y = maze.getCellPosition(mazeX, mazeY-1).y;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (maze.getColor(mazeX, mazeY+1) == sf::Color::White)
            position.y = maze.getCellPosition(mazeX, mazeY+1).y;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (maze.getColor(mazeX+1, mazeY) == sf::Color::White)
            position.x = maze.getCellPosition(mazeX+1, mazeY).x;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (maze.getColor(mazeX-1, mazeY) == sf::Color::White)
            position.x = maze.getCellPosition(mazeX-1, mazeY).x;
    }

    body.setPosition(position);
    sf::sleep(sf::milliseconds(50));
    //std::cout << "x: " << mazeX << " y: " << mazeY << std::endl;
    //std::cout << "x: " << position.x+10 << " y: " << position.y+10 << std::endl;
    return;
}
