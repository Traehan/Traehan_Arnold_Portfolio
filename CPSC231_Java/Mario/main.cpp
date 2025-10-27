#include "Level.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Item.h"
#include "Mario.h"

int main(){
    ifstream inputFile;
    inputFile.open("Input.txt");
    string line;
    string* gameParameters = new string[8];
    for (int i = 0; i < 8; i++) {
        std::getline(inputFile, line);
        gameParameters[i] = line;
    }
    int numLevels = stoi(gameParameters[0]);
    int dimensions = stoi(gameParameters[1]);
    int lives = stoi(gameParameters[2]);

    WriteFile writer("Output.txt");
    Level MainLevel(gameParameters);
    Item** levelGrid = MainLevel.createLevel(stoi(gameParameters[1]));
    Mario mario(0, lives, 0, mario.getRandom(0, dimensions-1), mario.getRandom(0, dimensions-1), levelGrid);

    string recentDirection = "none";
    for(int currentLevel=1; currentLevel<numLevels; currentLevel++){
        if (currentLevel != numLevels){
            cout << mario.levelGrid[0][0].name;
            while (mario.currentItem.name != "pipe") {
                writer.writeMarioInfo(mario, recentDirection, currentLevel);
                writer.printLevel(levelGrid);
                recentDirection = mario.move();
                mario.checkSquare(levelGrid);
                if(mario.checkSquare(levelGrid)=="pipe"){
                    continue;
                }
            }
        } else {
            // no pipe
            Item** levelGrid = MainLevel.createFinalLevel(stoi(gameParameters[1]));
            Mario mario(0, lives, 0, mario.getRandom(0, dimensions-1), mario.getRandom(0, dimensions-1), levelGrid);
        }
        writer.writeMarioInfo(mario, recentDirection, currentLevel);
        writer.printFinalLevel(levelGrid);
        levelGrid = MainLevel.createLevel(stoi(gameParameters[1]));
        mario.posx = mario.getRandom(0, stoi(gameParameters[1])-1);
        mario.posy = mario.getRandom(0, stoi(gameParameters[1])-1); 
        mario.levelGrid = levelGrid;
        mario.currentItem = levelGrid[mario.posx][mario.posy];
    }
}