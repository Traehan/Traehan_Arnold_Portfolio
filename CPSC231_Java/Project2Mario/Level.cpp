#include "Level.h"

using namespace std;


Level::Level(int N){
    dim = N;
    grid = new char*[dim];
    for (int i = 0; i < dim; ++i){
        grid[i] = new char[dim];
    }
}

Level::~Level(){
    for (int i = 0; i < dim; ++i){
        delete[] grid[i];
    }
    delete[] grid;
}

void Level::MakeLevel(int coinPercentage, int nothingPercentage, int goombaPercentage, int koopaPercentage, int mushroomPercentage){
    srand(time(0));

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            int rand_val = rand() % 100 + 1; // Random number between 1 and 100
            if (rand_val <= coinPercentage) {
                grid[i][j] = 'c';
            } else if (rand_val <= coinPercentage + nothingPercentage) {
                grid[i][j] = 'x';
            } else if (rand_val <= coinPercentage + nothingPercentage + goombaPercentage) {
                grid[i][j] = 'g';
            } else if (rand_val <= coinPercentage + nothingPercentage + goombaPercentage + koopaPercentage) {
                grid[i][j] = 'k';
            } else if (rand_val <= coinPercentage + nothingPercentage + goombaPercentage + koopaPercentage + mushroomPercentage) {
                grid[i][j] = 'm';
            } else {
                grid[i][j] = 'x';
            }
        }
    }

    // Place boss randomly
    boss_position.row = rand() % dimension;
    boss_position.col = rand() % dimension;
    grid[boss_position.row][boss_position.col] = 'b';

    // Place warp pipe randomly
    warp_pipe_position.row = rand() % dimension;
    warp_pipe_position.col = rand() % dimension;
    grid[warp_pipe_position.row][warp_pipe_position.col] = 'w';
}

void Level::print() {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}