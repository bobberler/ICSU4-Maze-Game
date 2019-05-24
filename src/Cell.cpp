#include "Cell.h"

Cell::Cell()
{
    square.setSize(sf::Vector2f(WIDTH/20, HEIGHT/20));
    square.setFillColor(sf::Color::Black);
    //ctor
}

Cell::~Cell()
{
    //dtor
}

void Cell::setColor(sf::Color color)
{
    square.setFillColor(color);
    return;
}

sf::Color Cell::getColor()
{
    return square.getFillColor();
}
