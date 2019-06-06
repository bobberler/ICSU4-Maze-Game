#ifndef BEING_H
#define BEING_H
#include <SFML/Graphics.hpp>
#include "Point.h"
class Being : public GameObject
{
    public:
        Being();
        virtual ~Being();

    protected:
        Point mazePos;

    private:
        int hp;
        int strength;
};

#endif // BEING_H
