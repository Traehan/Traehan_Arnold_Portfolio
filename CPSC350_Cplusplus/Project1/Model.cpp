#include "Model.h"

using namespace std;

Model::Model(){
}

Model::~Model(){
}

Model::translateSingleConsonant(char Consonant){
    if(CheckIfConsonant(Consonant)){
        return string(Consonant + "o" + Consonant);
    }
    return string(Consonant);


}

Model::translateSingleVowel(char Vowel){
    return string(Vowel);

}

bool Model::CheckIfConsonant(char Letter){
    char LowercaseLetter = tolower(Letter);
    bool isAlpha = isalpha(Letter);
    bool isNotVowel = LowercaseLetter != 'a' && LowercaseLetter != 'e' && LowercaseLetter != 'i' && LowercaseLetter != 'o' && LowercaseLetter != 'u'; 
    // Check if it's not a vowel
    return isAlpha && isNotVowel;
}