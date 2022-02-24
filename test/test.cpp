#include <iostream>
#include <string>
#include <vector>

using namespace std;
int *pArray = nullptr;
void array_allocate(int *&pARRAY, int INIT_SIZE){
    
    pARRAY = new int[INIT_SIZE];
}

void array_set_element_at(int *&pARRAY, int SIZE, int POS, int VALUE){

    int arraySize = 10;
    if (POS <= arraySize && POS >= 0){
        pARRAY[POS] = VALUE;
    }
}

int main(){
    int *pArray = nullptr;
    int currArraySize = 10;
    array_allocate(pArray, 10);

    cout << pArray << endl;

    for(int i = 0; i < currArraySize; i++) {
        array_set_element_at(pArray, currArraySize, i, 1);
    }
    for (int i = 0; i < 10; i++){
        cout << *&pArray[i] << endl;
    }
    return 0;

}