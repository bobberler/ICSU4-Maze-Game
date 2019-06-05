#ifndef BEING_H
#define BEING_H
#include <SFML/Graphics.hpp>
#include "Point.h"
class Being : public sf::Sprite
{
    public:
        Being(sf::Vector2f position);
        virtual ~Being();
        virtual void update();
        virtual void destroy();

    protected:
        Point mazePos;

    private:
        int hp;
//        sf::Texture* texture;
};

#endif // BEING_H
