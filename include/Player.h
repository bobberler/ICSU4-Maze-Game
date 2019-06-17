#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.h"
#include "Monster.h"
#include "Game.h"
#include "Stack.h"

class Game;
class Monster;

class Player : public Being
{
    public:
        Player(sf::Vector2f _position, std::string _name, int _hp, int _strength);
        virtual ~Player();
        void update();
        bool getKey();
        void fight(Monster*);
        static bool getWon();
        static bool getDead();
        static void setAutoSolve(bool);
        void autoSolveStep();

    protected:

    private:
        bool key;
        static bool won;
        static bool dead;
        static bool autoSolve;
        bool startedSolving;
        bool visited[20][20];
        Stack* solver;


};

#endif // PLAYER_H
