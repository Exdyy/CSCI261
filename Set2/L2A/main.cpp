using namespace std;

#include <iostream> 
#include <fstream>
#include <stdlib.h>

int main() {
    ofstream decode("test.txt");
    ifstream secretMessage("test.txt");


    if (secretMessage.fail()) {
        cerr << "Error opening output file";
        return -1;
    }

    secretMessage.open("test.txt");
    if (secretMessage.is_open()) { 

        decode << "Test test test" << endl;
        secretMessage.close();
        }


        return 0;
}