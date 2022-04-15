/* CSCI 261: Assignment 5: L5B - Sorting I: Sorting a List
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides
 * This program performs a bubble sort on an array of integers
 */
#include <iostream>
using namespace std;

void bubbleSort(int *&arr, int size){
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size - i; j++){
            if (arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
            }
        }
    }
}
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

    //Bubble sort algorithm defined above
    bubbleSort(array, 9);

    //Print sorted array after using bubble sort on original array
    for (int i = 0; i < 9; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}