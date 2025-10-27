#include "SpeakerView.h"
using namespace std;

SpeakerView::SpeakerView(string inputFileName) {
    this -> inputFileName = inputFileName;
}

MonoStack<double>** SpeakerView::processFile() {
    MonoStack<double>** ColumnArray = createArrayOfMonoStacks();
    ifstream inputFile;
    inputFile.open(inputFileName);
    string lineValue;
    getline(inputFile, lineValue);
    for (int i = 0; i < getFileLength(); i++) {
        getline(inputFile, lineValue);
        istringstream lineStream(lineValue);
        for (int j = 0; j < getHeightsPerRow(); j++) {
            double tempHeight;
            lineStream >> tempHeight;
            ColumnArray[j] -> push(tempHeight);
        }
    }
    return ColumnArray;
}

int SpeakerView::getFileLength() {
    int maxLines = 0;
    string lineValue;
    ifstream inputFile;
    inputFile.open(inputFileName);
    while (getline(inputFile, lineValue)) {
        maxLines += 1;
    };
    return maxLines - 2;
}

int SpeakerView::getHeightsPerRow() {
    int maxHeights = 1;
    string lineValue;
    ifstream inputFile;
    inputFile.open(inputFileName);
    getline(inputFile, lineValue);
    getline(inputFile, lineValue);
    for (int i = 0; i < lineValue.length(); i++) {
        if (lineValue[i] == ' ') {
            maxHeights += 1;
        }
    }
    return maxHeights;
}

MonoStack<double>** SpeakerView::createArrayOfMonoStacks() {
    MonoStack<double>** ColumnArray = new MonoStack<double>*[getHeightsPerRow()];

    for (int i = 0; i < getHeightsPerRow(); i++) {
        MonoStack<double>* column = new MonoStack<double>(getFileLength());
        ColumnArray[i] = column;
    }
    return ColumnArray;
}

void SpeakerView::printAll(MonoStack<double>** heightMonoStacks) {
    for (int i = 0; i < getHeightsPerRow(); i++) {
        heightMonoStacks[i] -> printStackStatus(i);
    }
}