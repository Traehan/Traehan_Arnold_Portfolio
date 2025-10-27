//This file contains the methods and data associated with mario, such as his coins, position, and other attributes related
//to his object

#include "Mario.h"
#include <random>


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
takes in a min and max and returns a random value between the 2
got this code from chat gpt
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
string Mario::checkTile(Item** levelGrid) {
    string tileName = levelGrid[posy][posx].name;
    levelGrid[posy][posx].name = "mario";
    if (tileName == "coin") {
        coins +=1;
    } else if (tileName == "mushroom") {
        powerLevel += 1;
    } else if (tileName == "goomba") {
        if (!winGoombaFight()) {
            levelGrid[posy][posx].name = "goomba";
            losePowerOrLife();
        }
    } else if (tileName == "koopa") {
        if (!winKoopaFight()) {
            levelGrid[posy][posx].name = "koopa";
            losePowerOrLife();
        }
    }
    // else if (tileName == "boss") {
    // }
    return tileName;
}

bool Mario::winGoombaFight() {
    if (getRandom(0, 100) > 20) {
        return true;
    } 
    return false;
}

bool Mario::winKoopaFight() {
    if (getRandom(0, 100) > 35) {
        return true;
    } 
    return false;
}

void Mario::losePowerOrLife() {
    if (powerLevel ==  0) {
        lives -= 1;
    } else {
        powerLevel -= 1;
    }
}

/*
generates a random int between 1 and 100 and checks to find which direction the number aligns with. 
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
moves mario based on the direction of moveDirection
returns a string of the direction
*/
string Mario::moveMario() {
    string direction = getDirection();
    levelGrid[posy][posx].name = "nothing";
    if (direction == "UP") {
        posy = getMovement(posy, -1, 4);
    } else if (direction == "RIGHT") {
        posx = getMovement(posx, 1, 4);
    } else if (direction == "DOWN") {
        posy = getMovement(posy, 1, 4);
    } else  {
        posx = getMovement(posx, -1, 4);
    }
    currentItem = levelGrid[posy][posx];
    return direction;
}

/*
changes the x or y position passed as currentPos by adding posChange to it and checks if the movement is still on the grid
returns the new current postion.
*/
int Mario::getMovement(int currentPos, int posChange, int gridWidth) {
    if (currentPos + posChange >= gridWidth) {
        currentPos = 0;
    } else if (currentPos + posChange < 0) {
        currentPos = gridWidth - 1;
    } else {
        currentPos += posChange;
    }
    return currentPos;
}