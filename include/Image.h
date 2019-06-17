#ifndef IMAGE_H
#define IMAGE_H

#include "GameObject.h"

class Image : public GameObject
{
    public:
        Image(sf::Vector2f, std::string, std::string);
        virtual ~Image();

    protected:

    private:
};

#endif // IMAGE_H
