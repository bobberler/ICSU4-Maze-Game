#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
#include "Being.h"

class Monster : public Being
{
    public:
        Monster(sf::Vector2f _position, int _layer, std::string _label, int _hp, int _strength);
        virtual ~Monster();

    protected:

    private:
};

#endif // MONSTER_H
