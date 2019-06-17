#include "Being.h"

Being::Being(sf::Vector2f _position, std::string _name, int _hp, int _strength) : GameObject(_position, _name)
{
    hp = _hp;
    strength = _strength;
    mazePos.x = _position.x/40;
    mazePos.y = _position.y/40; //each maze cell is 40 pixels wide
    //ctor
}

Being::~Being()
{
    //dtor
}

void Being::update()
{
    position.x = mazePos.x*40; //update position base on mazePosition
    position.y = mazePos.y*40;
    updatePosition();
    return;
}

Point Being::getMazePos()
{
    return mazePos;
}
