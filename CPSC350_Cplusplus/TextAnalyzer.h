#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <iostream> // pre-processor directive
using namespace std;

class TextAnalyzer{
    public:
    TextAnalyzer(); //constructor
    ~TextAnalyzer(); //deconstructor
    int countVowels(string userInput);


};

#endif