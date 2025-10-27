#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

using namespace std;

int main (int argc, char **argv){

    try{
        FileProcessor p;

        p.processFile("input.txt", "Project1.html");

        

        
        }

        

    


    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    

}