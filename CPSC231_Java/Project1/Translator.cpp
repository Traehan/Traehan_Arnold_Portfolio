#include "Translator.h"
#include "Model.h"

using namespace std;



Translator::Translator(){
}

Translator::~Translator(){
}

string Translator::translateEnglishWord(const string word) {
    Model model;
    string result;
    for (char letter : word) {
        if (isalpha(letter)) {
            if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u') {
                result += model.translateSingleVowel(letter);
            } else {
                result += model.translateSingleConsonant(letter);
            }
        } else {
            result += letter;
        }
    }
    return result;
}



string Translator::translateEnglishSentence(const string sentence) {
    string result;
    string word;
    for (char letter : sentence) {
        if (isalpha(letter) || letter == '\'') {
            word += letter;
        } else {
            result += translateEnglishWord(word);
            result += letter;
            word = "";
        }
    }
    result += translateEnglishWord(word);
    return result;
}
