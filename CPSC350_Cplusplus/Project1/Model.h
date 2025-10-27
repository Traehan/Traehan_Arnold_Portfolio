#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <exception>

using namespace std;

class Model{
    
    public:
       
       //Constructor and Deconstructo;
        Model();
        ~Model();

        //Aux Functions:

        string translateSingleConsonant(char Consonant);
        string translateSingleVowel(char Vowel);





    private:

    bool CheckIfConsonant(char Letter);




};

#endif