#include "Monster.h"

Monster::Monster(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength) : Being(_position, _layer, _label, _hp, _strength)
{
    texture.loadFromFile("assets/monster.png");
    sprite.setTexture(texture);
    //ctor
}

Monster::~Monster()
{
    //dtor
}
