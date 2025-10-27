#include "Level.h"

//constructs and fills the grid that mario moves in
Level::Level(string* gameParameters) {
    this->gameParameters = gameParameters;
}

//Iterates through the 2d array and fills it with randomly selected items, then places the boss and pipe in random locaations on the board 
//finally retruns the 2d array
Item** Level::createLevel(int gridDimension) {
    Item** levelGrid = new Item*[gridDimension];
    for (int i = 0; i < gridDimension; i++) {
        levelGrid[i] = new Item[gridDimension];
        for (int j = 0; j < gridDimension; j++) {
            levelGrid[i][j] = assignSquare();
        }
    }
    Item boss("boss");
    Item warpPipe("pipe");
    levelGrid[getRandom(0, gridDimension-1)][getRandom(0, gridDimension-1)] = warpPipe;
    levelGrid[getRandom(0, gridDimension-1)][getRandom(0, gridDimension-1)] = boss;
    return levelGrid;
}

//seperate method which is called when currentLevel = numLevels, does not include warp pipe
Item** Level::createFinalLevel(int gridDimension) {
    Item** levelGrid = new Item*[gridDimension];
    for (int i = 0; i < gridDimension; i++) {
        levelGrid[i] = new Item[gridDimension];
        for (int j = 0; j < gridDimension; j++) {
            levelGrid[i][j] = assignSquare();
        }
    }
    Item boss("boss");
    levelGrid[getRandom(0, gridDimension-1)][getRandom(0, gridDimension-1)] = boss;
    return levelGrid;
}

//each value has a percentage chance to pick 1 of the 5 items
//returns the item

Item Level::assignSquare() {
    int randomNumber = getRandom(0, 100);
    int percentageTotal = 0;
    string items[5] = {"coin", "nothing", "goomba", "koopa", "mushroom"};
    for (int i = 0; i < 5; i++) {
        percentageTotal += stoi(gameParameters[i + 3]);
        if (percentageTotal > randomNumber) {
            Item newItem(items[i]);
            return newItem;
            break;
        }
    }
    Item newItem("nothing");
    return newItem;
}

int Level::getRandom(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    int random_number = distribution(generator);
    return random_number;
}

