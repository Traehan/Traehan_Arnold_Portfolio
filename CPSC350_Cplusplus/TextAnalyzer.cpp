#include "TextAnalyzer.h" //user defined header (meant for the files you (me) make).

TextAnalyzer::TextAnalyzer(){ //classname::Filename
cout << "constructor" << endl;
}

TextAnalyzer::TextAnalyzer(){ 
cout << "constructor" << endl;
}

int TextAnalyzer::countVowels(string userInput){
    int count = 0;
    for(int i = 0; i < userInput.size(); ++i){
        
        if(tolower(userInput[i]) == 'a')
        count++;
        else if(tolower(userInput[i]) == 'e')
        count++;
        else if(tolower(userInput[i]) == 'i')
        count++;
        else if(tolower(userInput[i]) == 'o')
        count++;
        else if(tolower(userInput[i]) == 'u')
        count++;


    }
    return count;
}
