#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"
#include "Mario.h"
// #include "WorldGameplay.h"
using namespace std;

class FileWriter {
    public:
        FileWriter(string fileName);
        void writeBoard(Item** board);
        void writeMarioInfo(Mario mario, string recentDirection, int currentLevel);
        string fileName;
        ofstream outputFile;
};
#endif
