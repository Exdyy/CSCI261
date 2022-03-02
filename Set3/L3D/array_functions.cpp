#include "array_functions.h"
#include <iostream>
using namespace std;

void array_allocate(int *&pArray, int INIT_SIZE){
    pArray = new int[INIT_SIZE];
    for (int i = 0; i < INIT_SIZE; i++){
        pArray[i] = 0;
    }
}

int array_get_element_at(int *pARRAY, int SIZE, int POS){
    
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

void array_set_element_at(int *pARRAY, int SIZE, int POS, int VALUE){

    int arraySize = SIZE;
    if (POS <= arraySize && POS >= 0){
        int *arraySlot = pARRAY;
        arraySlot += POS;
        *arraySlot = VALUE;
    }
}

void array_deallocate(int *&pArray, int &size){
    delete pArray;
    pArray = nullptr;
    size = 0;
}

void array_insert_at_position(int *&pArray, int &size, int POS, int VALUE){

    size = size + 1;
    int *newArray = new int[size];
    array_allocate(newArray, size);
    if (POS >= size){
        POS = size - 1;
    }
    if (POS <= 0){
        POS = 0;
    }
    for (int i = 0; i < size; i++){
        if (i < POS){
            newArray[i] = pArray[i];
        } else if (i == POS){
            newArray[i] = VALUE;
        } else {
            newArray[i] = pArray[i-1];
        }
    }
    int *arraySlot = pArray;
    arraySlot += POS;
    *arraySlot = VALUE;
    delete pArray;
    pArray = newArray;
}

int array_min(int *pARRAY, int SIZE){
    if (pARRAY == nullptr || SIZE == 0){
        return 0;
    } else {
        int min = pARRAY[0];
        for (int i = 1; i < SIZE; i++){
            if (pARRAY[i] < min){
                min = pARRAY[i];
            }
        }
        return min;
    }
}

int array_max(int *pARRAY, int SIZE){
    if (pARRAY == nullptr || SIZE == 0){
        return 0;
    } else {
        int max = pARRAY[0];
        for (int i = 1; i < SIZE; i++){
            if (pARRAY[i] > max){
                max = pARRAY[i];
            }
        }
        return max;
    }
}

void array_remove_from_position(int *&pArray, int &size, int POS){

    bool skip = false;
    if (size > 0){
        size = size - 1;
        int *newArray = new int[size];
        array_allocate(newArray, size);
        if (POS >= size + 1){
            for (int i = 0; i < size; i++){
                newArray[i] = pArray[i];
            }
        }
        if (POS <= 0){
            POS = 0;
        }
        if (POS < size){
            for (int i = 0; i < size; i++){
                if (i == POS){
                    skip = true;
                }
                if (skip == false){
                    newArray[i] = pArray[i];
                } else {
                    newArray[i] = pArray[i+1];
                }
            }
        }
        delete pArray;
        pArray = newArray;
    } else if (size == 0){
        delete pArray;
        pArray = nullptr;
    }
}

int array_find(int *pARRAY, int SIZE, int TARGET){
    int found = -1;
    if (SIZE == 0){
        return -1;
    } else {
        for (int i = 0; i < SIZE && found < 0; i++){
            if (pARRAY[i] == TARGET){
                found = i;
            }
        }
        return found;
    }
}