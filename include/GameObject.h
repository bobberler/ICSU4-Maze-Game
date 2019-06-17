#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"
class LinkedList;

class GameObject
{
    public:
        GameObject(sf::Vector2f _position, std::string _name);
        virtual ~GameObject();
        virtual void update();
        virtual void destroy();
        void updatePosition();

        std::string getName();
        sf::Sprite getSprite();
        void setPosition(sf::Vector2f _position);

        static LinkedList* objects; //static linked list of all game objects

    protected:

        sf::Sprite sprite; //sfml sprite and texture sutff
        sf::Texture texture;
        sf::Vector2f position;
    private:
        std::string name;
};

#endif // GAMEOBJECT_H
