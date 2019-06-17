#ifndef BEING_H
#define BEING_H
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "GameObject.h"

class Being : public GameObject
{
    public:
        Being(sf::Vector2f _position, std::string _name, int _hp, int _strength);
        virtual ~Being();
        void update();
        Point getMazePos();

    protected:
        Point mazePos;
        int hp;
        int strength;

    private:
};

#endif // BEING_H
