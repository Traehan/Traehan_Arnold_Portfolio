#include "SpeakerView.h"
#include "MonoStack.h"


int main() {
    SpeakerView audience("audience.txt");
    MonoStack<double>** columns = audience.processFile();
    audience.printAll(columns);
    return 0;
}