#include "Mario.h"
#include <random>


/*contains data and methods that go with mario, 
like his power level, lives, position, 
and other attributes related to his object
*/
Mario::Mario(int coins, int lives, int powerLevel, int posx, int posy, Item** levelGridd) {
    this->coins = coins;
    this->lives = lives;
    this->powerLevel = powerLevel;
    this->posx = posx;
    this->posy = posy;
    this->levelGrid = levelGridd;
    this->currentItem = levelGrid[posy][posx];
    levelGrid[posy][posx].name = "mario";
}

Mario::Mario() {
    this->coins = 0;
    this->lives = 0;
    this->powerLevel = 0;
    this->posy = -1;
    this->posx = -1;
}

/*
returns a randome value between the min and max input
help from chatgpt
*/
int Mario::getRandom(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    int random_number = distribution(generator);
    return random_number;
}

/*
takes in a 2d pointer array of items that is indexed at mario's x and y coordinates to find the current item mario is at. 
Then it returns the name of that item
*/
/*
finds the x and y coordinate inside the 2D array levelGrid and pinpoints
the item mario moved to and returns that name
*/
string Mario::checkSquare(Item** levelGrid) {
    string tileName = levelGrid[posy][posx].name;
    levelGrid[posy][posx].name = "mario";
    if (tileName == "coin") {
        coins +=1;
    } else if (tileName == "mushroom") {
        powerLevel += 1;
    } else if (tileName == "goomba") {
        if (!goombaFight()) {
            levelGrid[posy][posx].name = "goomba";
            losePower();
        }
    } else if (tileName == "koopa") {
        if (!koopaFight()) {
            levelGrid[posy][posx].name = "koopa";
            losePower();
        }
    } 
    return tileName;
}

bool Mario::goombaFight() {
    if (getRandom(0, 100) > 20) {
        return true;
    } 
    return false;
}

bool Mario::koopaFight() {
    if (getRandom(0, 100) > 35) {
        return true;
    } 
    return false;
}

void Mario::losePower() {
    if (powerLevel ==  0) {
        lives -= 1;
    } else {
        powerLevel -= 1;
    }
}

/*
A random int generates between 1 and 100
and runs through the if statements to find which direction the number matches with. 
Returns a string of the direction
*/
string Mario::getDirection() {
    int rand = getRandom(1, 100);
    if (rand < 26) {
        return "UP";
    } else if (rand < 51) {
        return "RIGHT";
    } else if (rand < 76) {
        return "DOWN";
    } else {
        return "LEFT";
    }
}

/*
moves mario depending on the direction of getDirection
returns a string of the direction
*/
string Mario::move() {
    string direction = getDirection();
    levelGrid[posy][posx].name = "nothing";
    if (direction == "UP") {
        posy = doMove(posy, -1, 4);
    } else if (direction == "RIGHT") {
        posx = doMove(posx, 1, 4);
    } else if (direction == "DOWN") {
        posy = doMove(posy, 1, 4);
    } else  {
        posx = doMove(posx, -1, 4);
    }
    currentItem = levelGrid[posy][posx];
    return direction;
}

/*
and checks if the movement is still on the grid
changes the x and y position if needed 
returns the new current postion.
*/
int Mario::doMove(int currentPos, int posChange, int gridWidth) {
    if (currentPos + posChange >= gridWidth) {
        currentPos = 0;
    } else if (currentPos + posChange < 0) {
        currentPos = gridWidth - 1;
    } else {
        currentPos += posChange;
    }
    return currentPos;
}