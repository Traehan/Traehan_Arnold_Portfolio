#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Mario {
    public:
        Mario(int coins, int lives, int powerLevel, int posx, int posy, Item** levelGridd);
        Mario();
        int getRandom(int min, int max);
        void losePower();
        bool goombaFight();
        bool koopaFight();
        string checkSquare(Item** levelGrid);
        string move();
        string getDirection();
        int doMove(int currentPos, int posChange, int gridWidth);
        Item currentItem;
        Item** levelGrid;
        int coins;
        int lives;
        int powerLevel;
        int posy;
        int posx;
};
#endif