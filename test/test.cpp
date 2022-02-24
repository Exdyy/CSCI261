#include <iostream>
#include <string>
#include <vector>

using namespace std;

void array_allocate(int *&pARRAY, int INIT_SIZE){
    pARRAY = new int[INIT_SIZE];
}

int main(){
    int *pArray = nullptr;
    array_allocate(pArray, 10);

    cout << pArray << endl;
    return 0;

}