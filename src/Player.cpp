#include "Player.h"
#include "Game.h"
#include <cstring>

bool Player::dead;
bool Player::won;
bool Player::autoSolve;

Player::Player(sf::Vector2f _position, std::string _name, int _hp, int _strength) : Being(_position, _name, _hp, _strength)
{
    dead = false;
    won = false;
    startedSolving = false;
    autoSolve = false;
    solver = new Stack();
    memset(visited, false, sizeof(visited));//initialize visited array as all false;
    texture.loadFromFile("assets/player.png");
    sprite.setTexture(texture);
    key = false;
    for(int x = 0; x < hp; x++) //create as many hearts as hp
        Image* heart = new Image(sf::Vector2f(40*x, 0), "assets/heart.png", "heart"+std::to_string(x+1));

    //ctor
}

Player::~Player()
{
    //dtor
}

bool Player::getKey()
{
    return key;
}

bool Player::getDead()
{
    return dead;
}

bool Player::getWon()
{
    return won;
}

void Player::setAutoSolve(bool _autoSolve)
{
    autoSolve = _autoSolve;
}

void Player::update()
{
    if(autoSolve)//if autosolver is active
    {
        if(!startedSolving)//initial auto solving stuff (remove unnecessary gameObjects)
        {
            for(int y = 0; y < 20; y++)
            {
                for(int x = 0; x < 20; x++)
                {
                    if(Maze::maze[y][x] == 5)//remove monster from maze layout
                        Maze::maze[y][x] = 0;
                    if(Maze::maze[y][x] == 6)//remove healthpacks
                    {
                        Maze::maze[y][x] = 0;
                        GameObject::objects->remove(GameObject::objects->getLinkWithName("healthpack"+std::to_string(x)+std::to_string(y)));
                    }
                }
            }

            GameObject::objects->remove(GameObject::objects->getLinkWithName("monster1")); //remove monster sprites
            GameObject::objects->remove(GameObject::objects->getLinkWithName("monster2"));
            GameObject::objects->remove(GameObject::objects->getLinkWithName("monster3"));
            GameObject::objects->remove(GameObject::objects->getLinkWithName("monster4"));
            GameObject::objects->remove(GameObject::objects->getLinkWithName("hint"));
            for(int x = 0; x < hp; x++)
                GameObject::objects->remove(GameObject::objects->getLinkWithName("heart"+std::to_string(x+1)));
            startedSolving = true;
        }

        autoSolveStep();
    }
    else
    {
        int cellToMove; //value of the maze where the player is moving to
        if(Game::direction == 'U')//up
        {
            cellToMove = Maze::maze[mazePos.y-1][mazePos.x];
            if(cellToMove == 5)//fight monster
            {
                fight(Game::getMonsterWithLocation(Point(mazePos.x, mazePos.y-1)));
            }
            else if (cellToMove %2 == 0) //movable space
            {
                mazePos.y--;
            }

        }
        else if (Game::direction == 'L')//left
        {
            cellToMove = Maze::maze[mazePos.y][mazePos.x-1];
            if(cellToMove == 5)//fight monster
            {

                fight(Game::getMonsterWithLocation(Point(mazePos.x-1, mazePos.y)));
            }
            else if (cellToMove %2 == 0)
            {
               mazePos.x--;
            }

        }
        else if (Game::direction == 'D')//down
        {
            cellToMove = Maze::maze[mazePos.y+1][mazePos.x];
            if(cellToMove == 5)//fight monster
            {
                fight(Game::getMonsterWithLocation(Point(mazePos.x, mazePos.y+1)));
            }
            else if (cellToMove % 2 == 0)
            {
               mazePos.y++;
            }

        }
        else if (Game::direction == 'R')//right
        {
            cellToMove = Maze::maze[mazePos.y][mazePos.x+1];
            if(cellToMove == 5) //fight monster
            {
                fight(Game::getMonsterWithLocation(Point(mazePos.x+1, mazePos.y)));
            }
            else if (cellToMove % 2 == 0)
            {
                mazePos.x++;
            }

        }
        Game::direction = ' ';
        Being::update();//update position in window
        if(Maze::maze[mazePos.y][mazePos.x] == 6)//healthpack(refill health)
        {
            if(hp < 10) //if health is lost put it back to 10
            {
                GameObject::objects->remove(GameObject::objects->getLinkWithName("healthpack"+std::to_string(mazePos.x)+std::to_string(mazePos.y)));
                for(int x = hp; x < 10; x++)
                {
                    Image* heart = new Image(sf::Vector2f(40*x, 0), "assets/heart.png", "heart"+std::to_string(x+1));
                }
                hp = 10;
            }
        }
        if(hp <= 0) //dead
        {
        dead = true;
        Image* loser = new Image (sf::Vector2f(0,0), "assets/loser.png", "loser");
        }
    }
    if(Maze::maze[mazePos.y][mazePos.x] == 4)//key
    {
        key = true;
        GameObject::objects->remove(GameObject::objects->getLinkWithName("key")); //remove key and door
        GameObject::objects->remove(GameObject::objects->getLinkWithName("door"));
        Maze::maze[10][13] = 0;
        if(autoSolve)//reset autosolver if it's active
        {
            memset(visited, false, sizeof(visited));
            delete solver;
            solver = new Stack();
        }
    }
    if(Maze::maze[mazePos.y][mazePos.x] == 2)//player reached end
    {
        won = true;
        Image* winner = new Image (sf::Vector2f(0,0), "assets/winner.png", "winner");
    }
    return;
}

void Player::fight(Monster* monster) //monster's health gets subtracted by player's strength and vice versa
{
    int tempHp = hp;
    this->hp-=monster->getStrength();
    monster->setHp(monster->getHp()-this->strength);
    for(int i = tempHp; i > hp; i--) //remove hearts based on health lost
        GameObject::objects->remove(GameObject::objects->getLinkWithName("heart"+std::to_string(i)));

    return;
}

void Player::autoSolveStep()
{
    if(Maze::maze[mazePos.y+1][mazePos.x] % 2 == 0 and visited[mazePos.y+1][mazePos.x] == false)//down
    {
        solver->push('D');//push up
        visited[mazePos.y+1][mazePos.x] = true; //set location to true
        mazePos.y++; //move to location
    }
    else if(Maze::maze[mazePos.y][mazePos.x+1] % 2 == 0 and visited[mazePos.y][mazePos.x+1] == false)//right
    {
        solver->push('R');
        visited[mazePos.y][mazePos.x+1] = true;
        mazePos.x++;
    }
    else if(Maze::maze[mazePos.y-1][mazePos.x] % 2 == 0 and visited[mazePos.y-1][mazePos.x] == false)//up
    {
        solver->push('U');
        visited[mazePos.y-1][mazePos.x] = true;
        mazePos.y--;
    }
    else if(Maze::maze[mazePos.y][mazePos.x-1] % 2 == 0 and visited[mazePos.y][mazePos.x-1] == false)//left
    {
        solver->push('L');
        visited[mazePos.y][mazePos.x-1] = true;
        mazePos.x--;
    }
    else//backtracking
    {
        char backTrack = solver->pop();
        if(backTrack == 'U')//backtrack down
        {
            mazePos.y++;
        }
        else if (backTrack == 'D')//backtrack up
        {
            mazePos.y--;
        }
        else if (backTrack == 'R')//backtrack left
        {
            mazePos.x--;
        }
        else if (backTrack == 'L') //backtrack right
        {
            mazePos.x++;
        }
    }
    Being::update();//update position
    sf::sleep(sf::milliseconds(100)); //wait a bit
    return;
}
