#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "MonoStack.h"

using namespace std;

class SpeakerView {
    public:
        SpeakerView(string inputFileName);
        double* ParseFileIntoHeightArray();
        int getFileLength();
        int getHeightsPerRow();
        string inputFileName;
        MonoStack<double>** createArrayOfMonoStacks();
        MonoStack<double>** processFile();
        void printAll(MonoStack<double>** heightMonoStacks);
};
#endif