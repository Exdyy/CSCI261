#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int value;
    Node *pNext;
};

int main(){

    //PART 1: COMPLETE USING POINTER/ARRAY
    int newInt;
    int *pX = new int[3];
    for (int i = 0; i < 3; i++){
        cout << "\nPlease enter an integer: ";
        cin >> newInt;
        pX[i] = newInt;
    }
    cout << "Array contents: ";
    for (int i = 0; i < 3; i++){
        cout << pX[i] << ' ';
    }
    cout << endl;
    cout << "Backwards array contents: ";
    for (int i = 2; i >= 0; i--){
        cout << pX[i] << ' ';
    }
    cout << endl;
    delete pX;


    //PART 2: COMPLETE USING A LINKED LIST
    cout << "Part 2: Using a linked list" << endl;
    Node *pHead = new Node;
    for (int i = 0; i < 3; i++){
        cout << "Please enter an integer: ";
        cin >> newInt;
        (pHead+i)->value = newInt;
    }
    cout << "Array contents: ";
    for (int i = 0; i < 3; i++){
        cout << (pHead+i)->value << ' ';
    }
    cout << endl << "Backwards array contents: ";
    for (int i = 2; i >= 0; i--){
        cout << (pHead+i)->value << ' ';
    }
    cout << endl;
    delete pHead;
}