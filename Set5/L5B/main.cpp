#include "array_functions.h"
#include <iostream>
using namespace std;

int main(){
    //Allocate new array and set values as requested
    int *array = new int[9];
    array[0] = 4;
    array[1] = 3;
    array[2] = 8;
    array[3] = 1;
    array[4] = 5;
    array[5] = 9;
    array[6] = 7;
    array[7] = 2;
    array[8] = 6;

    //Print original, unsorted array
    for (int i = 0; i < 9; i++){
        cout << array[i] << ' ';
    }
    cout << endl;

    //Bubble sort algorithm
    for (int i = 0; i < 9; i++){
        for (int j = 1; j < 9-i; j++){
            if (array[j-1] > array[j]){
                swap(array[j-1], array[j]);
            }
        }
    }

    //Print sorted array after using bubble sort on original array
    for (int i = 0; i < 9; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}