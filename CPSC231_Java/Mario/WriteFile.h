#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"
#include "Mario.h"

using namespace std;

class WriteFile {
    public:
        WriteFile(string fileName);
        void printLevel(Item** board);
        void printFinalLevel(Item** board);
        void writeMarioInfo(Mario mario, string recentDirection, int currentLevel);
        string fileName;
        ofstream outputFile;
};
#endif