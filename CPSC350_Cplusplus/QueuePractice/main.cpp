#include "GenQueue.h"


int main (int argc, char **argv){

    GenQueue *myQueue = new GenQueue(5);

    try{
        myQueue->insert('f');
        myQueue->insert('o');
        myQueue->insert('o');
        myQueue->insert('b');
        myQueue->insert('a');

        cout << "PEEK: " << myQueue->peek() << endl;
        cout << "REMOVE: " << myQueue->remove() << endl;
        cout << "PEEK: " << myQueue->peek() << endl;

        myQueue->printArray();

    }
    catch(runtime_error &excpt){
        cerr << excpt.what() << endl;

    }

    delete myQueue;
    return 0;
}