#include "Image.h"

Image::Image(sf::Vector2f _position, int _layer, std::string _path, std::string _label) : GameObject(_position, _label, _layer)
{
    texture.loadFromFile(_path);
    sprite.setTexture(texture);
}

Image::~Image()
{
    //dtor
}
