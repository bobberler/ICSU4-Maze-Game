#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "LinkedList.h"
class LinkedList;

class GameObject
{
    public:
        GameObject(sf::Vector2f _position, std::string _name, int _layer);
        virtual ~GameObject();
        virtual void update();
        virtual void destroy();
        void draw(sf::RenderWindow& window);
        void updatePosition();

        int getLayer();
        std::string getName();
        sf::Sprite getSprite();
        void setPosition(sf::Vector2f _position);

        static LinkedList* objects;

    protected:
        int layer;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position;
//        sf::Text text;
//        sf::Font font;
    private:
        std::string name;
};

#endif // GAMEOBJECT_H
