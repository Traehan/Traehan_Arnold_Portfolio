#include "ReadFile.h"

//reads the file
ReadFile::ReadFile(string inputFileName) {
    this->inputFileName = inputFileName;
}


//takes the lines from the file and inputs it into an array, and returns the array
string* ReadFile::seperateLines() {
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    std::string line;
    std::string* gameParameters = new std::string[8];
    for (int i = 0; i < 8; i++) {
        std::getline(inputFile, line);
        gameParameters[i] = line;
    }
    return gameParameters;
}