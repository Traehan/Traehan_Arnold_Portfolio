//reads the input file and parses the text

FileReader::FileReader(string inputFileName) {
    this->inputFileName = inputFileName;
}

/*
takes the text from the input file and returns an array of strings filled with each line of the file.
*/
string* FileReader::processFile() {
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    std::string line;
    std::string* gameParameters = new std::string[8];
    for (int i = 0; i < 8; i++) {
        std::getline(inputFile, line);
        gameParameters[i] = line;
    }
    return gameParameters;
}
