#include "Hint.h"

Hint::Hint(sf::Vector2f _position, std::string _name) : GameObject(_position, _name)
{
    texture.loadFromFile("assets/hint.png", sf::IntRect(0,0, 40, 40));
    sprite.setTexture(texture);
    //ctor
}

Hint::~Hint()
{
    //dtor
}

void Hint::update()
{
    if(sprite.getGlobalBounds().contains(Game::mousePos.x, Game::mousePos.y))
    {
        texture.loadFromFile("assets/hint.png", sf::IntRect(40,0, 80, 40)); //light up the lightbulb
        sprite.setTexture(texture);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Player::setAutoSolve(true); //if it is clicked start autosolve
    }
    else
    {
        texture.loadFromFile("assets/hint.png", sf::IntRect(0,0, 40, 40));
        sprite.setTexture(texture);
    }
}
