#include "Hint.h"

Hint::Hint(sf::Vector2f _position, std::string _name) : GameObject(_position, _name)
{
    texture.loadFromFile("assets/hint.png");
    sprite.setTexture(texture);
    //ctor
}

Hint::~Hint()
{
    //dtor
}

void Hint::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) and sprite.getGlobalBounds().contains(Game::mousePos.x, Game::mousePos.y))
    {
        Player::setAutoSolve(true); //if it is clicked start autosolve
    }
}
