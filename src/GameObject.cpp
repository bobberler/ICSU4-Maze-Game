#include "GameObject.h"

GameObject::GameObject(sf::Vector2f _position, std::string _name)
{
    //ctor
    position = _position;
    name = _name;
    objects->add(this, objects->getLast());//add this objects that got created to the linked list
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

sf::Sprite GameObject::getSprite()
{
    return sprite;
}

void GameObject::updatePosition()
{
    sprite.setPosition(position);
	return;
}

std::string GameObject::getName()
{
    return name;
}

void GameObject::setPosition(sf::Vector2f _position)
{
    position = _position;
}
