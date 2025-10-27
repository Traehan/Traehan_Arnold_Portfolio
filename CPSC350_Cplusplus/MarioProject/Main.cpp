#include "FileReader.h"
#include "FileWriter.h"
#include "Mario.h"
#include "EnvironmentInteraction.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    FileReader fileRead("MarioInput.txt");
    std::cout << endl;
    string* gameParameters = fileRead.processFile();

    int numLevels = stoi(gameParameters[0]);

    EnvironmentInteraction MainEnvironmentInteraction(gameParameters);

    Item** levelGrid = MainEnvironmentInteraction.createLevelGrid(stoi(gameParameters[1]));

    Mario mario(0, stoi(gameParameters[2]), 0, mario.getRandom(0, stoi(gameParameters[1])-1), mario.getRandom(0, stoi(gameParameters[1])-1), levelGrid);

    FileWriter writer("MarioOutput.txt");

    string recentDirection = "none";
    for (int currentLevel = 1; currentLevel <= numLevels; currentLevel += 1) {
        cout << mario.levelGrid[0][0].name;
        while (mario.currentItem.name != "pipe") {
            writer.writeMarioInfo(mario, recentDirection, currentLevel);
            writer.writeBoard(levelGrid);
            recentDirection = mario.moveMario();
            mario.checkTile(levelGrid);
        }
        writer.writeMarioInfo(mario, recentDirection, currentLevel);
        writer.writeBoard(levelGrid);
        levelGrid = MainEnvironmentInteraction.createLevelGrid(stoi(gameParameters[1]));
        mario.posx = mario.getRandom(0, stoi(gameParameters[1])-1);
        mario.posy = mario.getRandom(0, stoi(gameParameters[1])-1); 
        mario.levelGrid = levelGrid;
        mario.currentItem = levelGrid[mario.posx][mario.posy];
    }
    return 0;
};