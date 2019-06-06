#include "GameObject.h"

GameObject::GameObject(sf::Vector2f _position, std::string _path, std::string _name, int _layer)
{
    //ctor
    sprite.setPosition(_position);
    sprite.setTexture(_path)
    name = _name;
    layer = _layer;
    objects->add(this, objects->getLast);
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::update()
{
    return;
}

void GameObject::destroy()
{
    return;
}

int GameObject::getLayer()
{
    return layer;
}

std::string GameObject::getName()
{
    return name;
}
