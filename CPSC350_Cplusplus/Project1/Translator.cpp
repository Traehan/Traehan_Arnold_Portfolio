#include "Translator.h"


using namespace std;

class Translator{

Translator::Translator(){
}

Translator::~Translator(){
}

Translator::translateEnglishWord(string word){
    string result;
    for(char i = 0; i < word.length(); ++i){
        if(isalpha(word[i])){
            if(tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || tolower(word[i]) == 'i' || std::tolower(word[i]) == 'o' || std::tolower(word[i]) == 'u'){
                result += model.translateSingleVowel(word[i]);
            } else {
                result += model.translateSingleConsonant(word[i]);
            }
        } else {
            result += word[i];
        }
    }
    return result;
}

Translator::translateEnglishSentence(string sentence){
    string result;
    for(char i = 0; i < sentence.length(); ++i){
        result += translateEnglishWord(sentence[i]);
    }
    return result;
}

}