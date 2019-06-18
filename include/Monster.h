#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
#include "Being.h"
#include "Maze.h"

class Monster : public Being
{
    public:
        Monster(sf::Vector2f _position, std::string _name, int _hp, int _strength);
        virtual ~Monster();
        int getHp();
        void setHp(int _hp);
        int getStrength();
        void update();

    protected:

    private:
        bool dead;
};

#endif // MONSTER_H
