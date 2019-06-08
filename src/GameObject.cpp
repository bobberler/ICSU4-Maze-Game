#include "GameObject.h"

GameObject::GameObject(sf::Vector2f _position, std::string _name, int _layer)
{
    //ctor
    position = _position;
    name = _name;
    layer = _layer;
    objects->add(this, objects->getLast());
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

void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Sprite GameObject::getSprite()
{
    return sprite;
}

int GameObject::getLayer()
{
    return layer;
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
