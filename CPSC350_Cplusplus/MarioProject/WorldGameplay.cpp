#include "EnvironmentInteraction.h"

//creates and fills the grid that mario moves within

EnvironmentInteraction::EnvironmentInteraction(string* gameParameters) {
    this->gameParameters = gameParameters;
}


//Iterates through the 2d array and fills it with randomly selected items, then places the boss and pipe in random locaations on the board 
//finally retruns the 2d array

Item** EnvironmentInteraction::createLevelGrid(int gridDimension) {
    Item** levelGrid = new Item*[gridDimension];
    for (int i = 0; i < gridDimension; i++) {
        levelGrid[i] = new Item[gridDimension];
        for (int j = 0; j < gridDimension; j++) {
            levelGrid[i][j] = selectItem();
        }
    }
    Item boss("boss");
    Item warpPipe("pipe");
    levelGrid[getRandom(0, gridDimension-1)][getRandom(0, gridDimension-1)] = warpPipe;
    levelGrid[getRandom(0, gridDimension-1)][getRandom(0, gridDimension-1)] = boss;
    return levelGrid;
}


//uses the values associated with the percentage chances to pick one of the 5 semi random items
//returns the item


Item EnvironmentInteraction::selectItem() {
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

int EnvironmentInteraction::getRandom(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    int random_number = distribution(generator);
    return random_number;
}

