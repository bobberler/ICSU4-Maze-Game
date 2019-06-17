#include "Monster.h"

Monster::Monster(sf::Vector2f _position, std::string _name, int _hp, int _strength) : Being(_position, _name, _hp, _strength)
{
    texture.loadFromFile("assets/monster.png");
    sprite.setTexture(texture);
    //ctor
}

Monster::~Monster()
{
    //dtor
}

int Monster::getHp()
{
    return hp;
}

void Monster::setHp(int _hp)
{
    hp = _hp;
    return;
}

int Monster::getStrength()
{
    return strength;
}

void Monster::update()
{
    if(hp <= 0) //delete itself if it is dead
    {
        GameObject::objects->remove(GameObject::objects->getLinkWithName(getName()));
        Maze::maze[mazePos.y][mazePos.x] = 0;
    }
}
