#include "Image.h"

Image::Image(sf::Vector2f _position, std::string _path, std::string _name) : GameObject(_position, _name)
{
    texture.loadFromFile(_path); //load texture
    sprite.setTexture(texture); //set object to said texture
}

Image::~Image()
{
    //dtor
}
