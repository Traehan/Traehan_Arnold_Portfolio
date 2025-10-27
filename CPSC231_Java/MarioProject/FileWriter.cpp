#include "FileWriter.h"

FileWriter::FileWriter(string fileName) {
    this->fileName = fileName;
    outputFile.open(fileName);
}

/*
translates the names of each item to the designated names and writes them to the file.
*/

void FileWriter::writeBoard(Item** board) {
    // int gridDimension = sizeof(board[0]);
    int gridDimension = 4;
    for (int i = 0; i < gridDimension; i++) {
        for (int j = 0; j < gridDimension; j++) {
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

/*
takes in mario and writes out his attributes and some other data associated with the level
*/
void FileWriter::writeMarioInfo(Mario mario, string recentDirection, int currentLevel) {
    outputFile << endl;
    outputFile << "Level: " << currentLevel << ". " << "Mario just moved " << recentDirection << ". Mario is at position: (x = " << mario.posx + 1 << ", y = " << mario.posy + 1 << "). Mario is at power level " << mario.powerLevel << endl;
    outputFile << "Mario encountered a " << mario.currentItem.name << ". Mario has " << mario.lives << " lives left. Mario has " << mario.coins << " coins." << endl;
    outputFile << "=================" << endl;
}
