#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

using namespace std;

struct Position {
    int row;
    int col;
};


class Level{

    public:
    Level(int N);
    ~Level();
    void MakeLevel(int coinChance, int mushroomChance, int goombaChance, int koopaChance, int nothingChance);
    void print();
    char getGridValue(int row, int col);
    void setGridValue(int row, int col, char value);
    Position getBossPosition();
    Position getWarpPipePosition();
    int getDimension();
    

    private:
    int dim;
    char** grid;
    Position boss_position;
    Position warp_pipe_position;
    int dimension;
};

#endif