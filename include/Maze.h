#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include "Image.h"
#include "GameObject.h"
#include "Point.h"

class Maze
{
    public:
        Maze();
        virtual ~Maze();

        //static int maze[20][20];

    protected:

    private:
        bool autoSolver;
        int maze[20][20];

};

#endif // MAZE_H
