#include "Being.h"

Being::Being(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength) : GameObject(_position, _label, _layer)
{
    hp = _hp;
    strength = _strength;
    mazePos.x = _position.x/40;
    mazePos.y = _position.y/40;
    //ctor
}

Being::~Being()
{
    //dtor
}
