#include "Model.h"

using namespace std;

Model::Model(){
}

Model::~Model(){
}

string Model::translateSingleConsonant(char Consonant){
    string result;
    if(CheckIfConsonant(Consonant)){
        result += Consonant;
        result += "o";
        result += Consonant;
    }
    return result;


}

string Model::translateSingleVowel(char Vowel){
    string result;
    result += Vowel;
    return result;

}

bool Model::CheckIfConsonant(char Letter){
    char LowercaseLetter = tolower(Letter);
    bool isNotVowel = LowercaseLetter != 'a' && LowercaseLetter != 'e' && LowercaseLetter != 'i' && LowercaseLetter != 'o' && LowercaseLetter != 'u'; 
    // Check if it's not a vowel
    return isNotVowel;
}