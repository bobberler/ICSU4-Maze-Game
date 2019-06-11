#ifndef BEING_H
#define BEING_H
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "GameObject.h"
class Being : public GameObject
{
    public:
        Being(sf::Vector2f _position, int _layer, std::string _name, int _hp, int _strength);
        virtual ~Being();

    protected:
        Point mazePos;

    private:
        int hp;
        int strength;
};

#endif // BEING_H
