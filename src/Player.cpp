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
    sf::Vector2f TL = body.getPosition();

    sf::Vector2f TR = body.getOrigin();
    TR.x += size;

    sf::Vector2f BL = body.getOrigin();
    BL.y -= size;

    sf::Vector2f BR = body.getOrigin();
    BR.x += size;
    BR.y -= size;
    sf::Vector2f center = sf::Vector2f(position.x+10, position.y+10);

//    if (TL.x < maze.getCellPosition(mazeX, mazeY).x or TL.y > maze.getCellPosition(mazeX, mazeY).y)
//        std::cout << "jksdfn";



    return;
}

void Player::update(Maze& maze)
{
    mazeX = (position.x+body.getRadius())*20/WIDTH;//calculates the cell in the maze its in
    mazeY = (position.y+body.getRadius())*20/HEIGHT;
    checkCollision();
    if (autoSolver == true)
        recursiveSolve(maze, 1, 1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        position.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        position.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        position.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        position.x -= speed;
    body.setPosition(position);
    //std::cout << "x: " << mazeX << " y: " << mazeY << std::endl;
    //std::cout << "x: " << position.x+10 << " y: " << position.y+10 << std::endl;
    return;
}

bool Player::recursiveSolve(Maze& maze, int autoX, int autoY);
{
    maze.setFillColor(autoX, autoY, sf::Color Blue);
    if (autoX == ENDX and autoY == ENDY)
        return true;

    if (maze.getColor(autoX, autoY-1) == sf::Color::White and recursiveSolve(maze, autoX, autoY-1)) //up
    {
        return true;
    }
    if (maze.getColor(autoX, autoY+1) == sf::Color::White and recursiveSolve(maze, autoX, autoY+1)) //down
    {
        return true;
    }
    if (maze.getColor(autoX-1, autoY) == sf::Color::White and recursiveSolve(maze, autoX-1, autoY)) //left
    {
        return true;
    }
    if (maze.getColor(autoX+1, autoY) == sf::Color::White and recursiveSolve(maze, autoX+1, autoY)) //right
    {
        return true;
    }
    maze.setFillColor(autoX, autoY, sf::Color White);
}
