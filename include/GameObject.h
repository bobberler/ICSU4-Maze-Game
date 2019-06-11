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

        static LinkedList* objects;

    protected:
        int layer;
        sf::Sprite sprite;
        sf::Texture texture;
//        sf::Text text;
//        sf::Font font;
    private:
        std::string name;
        sf::Vector2f position;
};

#endif // GAMEOBJECT_H
