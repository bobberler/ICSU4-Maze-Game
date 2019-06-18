#include "Monster.h"

Monster::Monster(sf::Vector2f _position, std::string _name, int _hp, int _strength) : Being(_position, _name, _hp, _strength)
{
    texture.loadFromFile("assets/monster.png", sf::IntRect(0,0, 40, 40));
    sprite.setTexture(texture);
    dead = false;
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
    if(dead == true)
    {
        GameObject::objects->remove(GameObject::objects->getLinkWithName(getName()));//remove the monster
        Maze::maze[mazePos.y][mazePos.x] = 0;
    }
    if(hp <= 0) //delete itself if it is dead
    {
        texture.loadFromFile("assets/monster.png", sf::IntRect(40,0, 80, 40)); //make the monster poof
        sprite.setTexture(texture);
        sf::sleep(sf::milliseconds(200));
        dead = true;
    }
    return;
}
