#include "array_functions.h"
#include <iostream>
using namespace std;

void array_allocate(int *&pARRAY, int INIT_SIZE){
    
    pARRAY = new int[INIT_SIZE];
}

int array_get_element_at(int *&pARRAY, int SIZE, int POS){
    
    int arraySize = 10;
    int element = 0;
    if (SIZE < arraySize && SIZE > 0){
        element = *pARRAY + POS;
    } 
    return element;
}

void array_set_element_at(int *&pARRAY, int SIZE, int POS, int VALUE){

    int arraySize = 10;
    if (POS <= arraySize && POS >= 0){
        int *arraySlot = pARRAY;
        arraySlot += POS;
        *arraySlot = VALUE;
        cout << "POS " << POS << ": ";
        for (int i = 0; i < arraySize; i++){
            cout << *arraySlot << ' ';
        }
        cout << endl;
    }
}