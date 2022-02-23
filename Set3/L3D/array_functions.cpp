#include "array_functions.h"

void array_allocate(int *pARRAY, int INIT_SIZE){
    int array[INIT_SIZE] = {0};
    pARRAY = new int[INIT_SIZE];
}