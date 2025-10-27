#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <exception>

using namespace;

class Translator{
    
    public:
        Translator();
        ~Translator();

        //Aux Functions:

        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);





    private:
        Model model;



};

#endif