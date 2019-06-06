#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
    public:
        GameObject(sf::Vector2f, std::string, std::string, int);
        virtual ~GameObject();
        virtual void update();
        virtual void destroy();

        int getLayer();
        std::string getName();

        static LinkedList* objects;

    protected:
        sf::Sprite sprite;
        int layer;
    private:
        std::string name;
};

#endif // GAMEOBJECT_H
