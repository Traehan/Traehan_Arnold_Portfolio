#include "TextAnalyzer.h"

int main(int argc, char **argv){

    if(argc < 2) {
        cerr << "invalid parameter count" << endl;
        return -1;    
    }

    TextAnalyzer ta; //stack, short term/ temporary storage
    TextAnalyzer *ta2 = new TextAnalyzer(); //heap, long term storage until garbage collected

    cout << "ARGC" argc << endl;
    cout << "ARGV" argv[1] << endl;

    cout << "VOWEL COUNT:" << ta.countVowels("foobarfoobar") << endl;
    cout << "VOWEL COUNT:" << ta2.countVowels("foobarfoobar") << endl;

    delete ta2; //garbage collect second stack
    return 0;
}