#ifndef HINT_H
#define HINT_H

#include "GameObject.h"
#include "Player.h"
#include "Game.h"

class Hint : public GameObject
{
    public:
        Hint(sf::Vector2f _position, std::string _name);
        virtual ~Hint();
        void update();

    protected:

    private:
};

#endif // HINT_H
