#ifndef CELL_H
#define CELL_H

#include "Game.h"

#include <SFML/Graphics.hpp>


class Cell
{
    public:
        Cell();
        virtual ~Cell();
        void setColor(sf::Color);
        sf::Color getColor();


    protected:

    private:
        sf::RectangleShape square;
};

#endif // CELL_H
