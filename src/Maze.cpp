#include "Maze.h"

Maze::Maze()
{
//    for (int x = 0; x < MAZE_HEIGHT; x++)
//    {
//        for (int y = 0; y < MAZE_WIDTH; y++)
//        {
//            cell[y][x].setSize(sf::Vector2f(WIDTH/MAZE_WIDTH, HEIGHT/MAZE_HEIGHT));
//            cell[y][x].setPosition(sf::Vector2f(WIDTH/MAZE_WIDTH*y, HEIGHT/MAZE_HEIGHT*x));
//            cell[y][x].setFillColor(sf::Color::Black);
////            cell[y][x].setOutlineThickness(3);
////            cell[y][x].setOutlineColor(sf::Color::White);
//        }
//    }
    std::string path = "maze1.txt";
    std::fstream mazeFile;
    if (!std::ifstream (path)) // make the file if it does not exist
    {
        std::cout << "error loading file";
        return;
    }
    mazeFile.open(path, std::fstream::in); // opens file
    char in;
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            cell[y][x].setSize(sf::Vector2f(WIDTH/MAZE_WIDTH, HEIGHT/MAZE_HEIGHT));
            cell[y][x].setPosition(sf::Vector2f(WIDTH/MAZE_WIDTH*x, HEIGHT/MAZE_HEIGHT*y));
            mazeFile >> in;
            if(in == 'w')//wall
                cell[y][x].setFillColor(sf::Color::Black);
            else if(in == 's')//space
                cell[y][x].setFillColor(sf::Color::White);
        }
    }
    mazeFile.close();
    return;
}

Maze::~Maze()
{
    //dtor
}

void Maze::drawMaze(sf::RenderWindow& window)
{
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            window.draw(cell[y][x]);
        }
    }
    return;
}


