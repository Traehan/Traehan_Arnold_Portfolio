#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <fstream>
using namespace std;

class Translator{
    
    public:
        Translator();
        ~Translator();

        //Aux Functions:

        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);





};

#endif