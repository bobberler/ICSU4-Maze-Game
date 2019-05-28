#include "Player.h"


Player::Player(sf::Vector2f startPosition)
{
    body.setRadius(10);
    size = body.getRadius()*2;
    body.setFillColor(sf::Color::Red);
    position = startPosition;
    body.setPosition(position);
    speed = 2;
    autoSolver = false;
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

void Player::checkCollision()
{
    if (body.getGlobalBounds().intersects(maze.getCell(mazeX+1, mazeY).getGlobalBounds()) and maze.getColor(mazeX+1, mazeY) == sf::Color::Black)
    {
        position.x -= speed;
    }
    if (body.getGlobalBounds().intersects(maze.getCell(mazeX-1, mazeY).getGlobalBounds()) and maze.getColor(mazeX-1, mazeY) == sf::Color::Black)
    {
        position.x += speed;
    }
    if (body.getGlobalBounds().intersects(maze.getCell(mazeX, mazeY+1).getGlobalBounds()) and maze.getColor(mazeX, mazeY+1) == sf::Color::Black)
    {
        position.y -= speed;
    }
    if (body.getGlobalBounds().intersects(maze.getCell(mazeX, mazeY-1).getGlobalBounds()) and maze.getColor(mazeX, mazeY-1) == sf::Color::Black)
    {
        position.y += speed;
    }
    return;
}

void Player::update()
{
    mazeX = (position.x+body.getRadius())*20/WIDTH;//calculates the cell in the maze its in
    mazeY = (position.y+body.getRadius())*20/HEIGHT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        position.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        position.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        position.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        position.x -= speed;
    checkCollision();
    body.setPosition(position);
    //std::cout << "x: " << mazeX << " y: " << mazeY << std::endl;
    //std::cout << "x: " << position.x+10 << " y: " << position.y+10 << std::endl;
    return;
}
