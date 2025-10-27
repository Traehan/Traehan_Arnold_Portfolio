#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader {
    public: 
        FileReader(string inputFileName);
        string inputFileName;
        string* processFile();
};