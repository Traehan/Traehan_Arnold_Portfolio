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

int coin_percentage = 30;
int nothing_percentage = 30;
int goomba_percentage = 20;
int koopa_percentage = 10;
int mushroom_percentage = 10;

void Level::MakeLevel()(int coin_percentage, int nothing_percentage, int goomba_percentage, int koopa_percentage, int mushroom_percentage) {
    srand(time(0));

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            int rand_val = rand() % 100 + 1; // Random number between 1 and 100
            if (rand_val <= coin_percentage) {
                grid[i][j] = 'c';
            } else if (rand_val <= coin_percentage + nothing_percentage) {
                grid[i][j] = 'x';
            } else if (rand_val <= coin_percentage + nothing_percentage + goomba_percentage) {
                grid[i][j] = 'g';
            } else if (rand_val <= coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage) {
                grid[i][j] = 'k';
            } else if (rand_val <= coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage + mushroom_percentage) {
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