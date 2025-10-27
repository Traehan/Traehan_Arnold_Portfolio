#include <fstream>
#include <string>
using namespace std;

class ReadFile {
    public: 
        ReadFile(string inputFileName);
        string inputFileName;
        string* seperateLines();
};