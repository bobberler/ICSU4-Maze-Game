#ifndef BEING_H
#define BEING_H
#include <SFML/Graphics.hpp>

class Being
{
    public:
        Being();
        virtual ~Being();

    protected:

    private:
        sf::Texture* texture;
        int hp;
        int mazeX;
        int mazeY;
        sf::Vector2f position;
};

#endif // BEING_H
