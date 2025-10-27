#include "FileProcessor.h"
#include "Translator.h"

FileProcessor::FileProcessor() {}

FileProcessor::~FileProcessor() {}


void FileProcessor::processFile(const string input_file, const string htmlFile) {
    ifstream in_file;
    string line;
    Translator translate;

    try{
        in_file.open(input_file);
    } catch (int a){
        cout << "File doesn't exist" << endl;
    }
    getline(in_file,line);

    string output = translate.translateEnglishSentence(line);
    string htmlContent = "<!DOCTYPE html>\n <html>\n <head>\n <title>Robber Language Translation</title>\n</head>\n<body>\n<h1><b>" + line + "</b></h1>\n<h1></h1>\n<h1><i>" + output + "</i></h1>\n</body>\n</html>\n";
    ofstream outFile(htmlFile);

    if (outFile.is_open()) {
        outFile << htmlContent;
        

        outFile.close();
        cout << "HTML file created successfully." << endl;
    } else {
        cerr << "Error: Unable to create HTML file." << endl;
    }

}