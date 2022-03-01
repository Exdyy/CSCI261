#include "array_functions.h"
#include <iostream>
using namespace std;

void array_allocate(int *&pARRAY, int INIT_SIZE){
    pARRAY = new int[INIT_SIZE];
    for (int i = 0; i < INIT_SIZE; i++){
        pARRAY[i] = 0;
    }
}

int array_get_element_at(int *&pARRAY, int SIZE, int POS){
    
    int arraySize = 10;
    int element = 0;
    if (SIZE <= arraySize && SIZE > 0){
        if (POS < 0 || POS >= arraySize){
            element = 0;
        } else {
            element = *(pARRAY + POS);
        }
    }
    return element;
}

void array_set_element_at(int *&pARRAY, int SIZE, int POS, int VALUE){

    int arraySize = SIZE;
    if (POS <= arraySize && POS >= 0){
        int *arraySlot = pARRAY;
        arraySlot += POS;
        *arraySlot = VALUE;
        // cout << "POS " << POS << ": ";
        // for (int i = 0; i < arraySize; i++){
        //     cout << pARRAY[i] << ' ';
        // }
        // cout << endl;
    }
}

void array_deallocate(int *&pARRAY, int &SIZE){
    delete pARRAY;
    pARRAY = nullptr;
    SIZE = 0;
}

void array_insert_at_position(int *&pARRAY, int &SIZE, const int &POS, int VALUE){

    SIZE += 1;
    int pos = POS;
    array_allocate(pARRAY, SIZE);
    cout << "DEBUG_ALLOCATION: ";
    for (int i = 0; i < SIZE; i++){
        cout << pARRAY[i] << " ";
    }
    cout << endl;
    if (pos <= 0){
        pos = 0;
    } else if (POS >= SIZE){
        pos = SIZE;
    }
    array_set_element_at(pARRAY, SIZE, pos, VALUE);

}