#include "WriteFile.h"
#include "ReadFile.h"

WriteFile::WriteFile(string fileName) {
    this->fileName = fileName;
    outputFile.open(fileName);
}

/*
translates the names of each item to the matching names and writes them to the file.
*/

void WriteFile::printLevel(Item** board) {
     
    int gridDimensions;
    ifstream inputFile;
    inputFile.open("Input.txt");
    string line;
    string* gameParameters = new std::string[8];
    
    for (int i = 0; i < 8; i++) {
        std::getline(inputFile, line);
        gameParameters[i] = line;
    }
    gridDimensions = stoi(gameParameters[1]);

    for (int i = 0; i < gridDimensions; i++) {
        for (int j = 0; j < gridDimensions; j++) {
            string itemName = board[i][j].name;
            if (itemName == "nothing") {
                outputFile << "x ";
            } else if (itemName == "mushroom") {
                outputFile << "m ";
            } else if (itemName == "coin") {
                outputFile << "c ";
            } else if (itemName == "goomba") {
                outputFile << "g ";
            } else if (itemName == "koopa") {
                outputFile << "k ";
            } else if (itemName == "boss") {
                outputFile << "b ";
            } else if (itemName == "pipe") {
                outputFile << "w ";
            } else if (itemName == "mario") {
                outputFile << "H ";
            } else {
                outputFile << "_ ";
            }
        }
        outputFile << endl;
    }
}

void WriteFile::printFinalLevel(Item** board) {
     
    int gridDimensions;
    ifstream inputFile;
    inputFile.open("Input.txt");
    string line;
    string* gameParameters = new std::string[8];
    
    for (int i = 0; i < 8; i++) {
        std::getline(inputFile, line);
        gameParameters[i] = line;
    }
    gridDimensions = stoi(gameParameters[1]);

    for (int i = 0; i < gridDimensions; i++) {
        for (int j = 0; j < gridDimensions; j++) {
            string itemName = board[i][j].name;
            if (itemName == "nothing") {
                outputFile << "x ";
            } else if (itemName == "mushroom") {
                outputFile << "m ";
            } else if (itemName == "coin") {
                outputFile << "c ";
            } else if (itemName == "goomba") {
                outputFile << "g ";
            } else if (itemName == "koopa") {
                outputFile << "k ";
            } else if (itemName == "boss") {
                outputFile << "b ";
            } else if (itemName == "pipe") {
                itemName = "nothing";
                outputFile << "x ";
            } else if (itemName == "mario") {
                outputFile << "H ";
            } else {
                outputFile << "_ ";
            }
        }
        outputFile << endl;
    }
}

/*
takes in mario and writes out his attributes and some other data depending on his actions
*/
void WriteFile::writeMarioInfo(Mario mario, string recentDirection, int currentLevel) {
    outputFile << endl;
    outputFile << "Level: " << currentLevel << ". " << "Mario just moved " << recentDirection << ". Mario is at position: (x = " << mario.posx + 1 << ", y = " << mario.posy + 1 << "). Mario is at power level " << mario.powerLevel << endl;
    outputFile << "Mario encountered a " << mario.currentItem.name << ". Mario has " << mario.lives << " lives left. Mario has " << mario.coins << " coins." << endl;
    outputFile << "=================" << endl;
}