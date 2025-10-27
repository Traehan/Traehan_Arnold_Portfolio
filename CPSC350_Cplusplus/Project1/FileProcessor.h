#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <exception>


class FileProcessor{

    public:
    FileProcessor();
    ~FileProcessor();
    
    //Aux Functions

    void processFile(string original, string translated);


    private:

    Translator translate;



};

#endif