#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Node {
    int value;
    Node *pNext = nullptr;
};

int main(){

    //PART 1: COMPLETE USING POINTER/ARRAY
    cout << "Part 1: Using an array" << endl;
    int newInt;
    int *pX = new int[3];
    for (int i = 0; i < 3; i++){
        cout << setw(28) << "Please enter an integer: ";
        cin >> newInt;
        pX[i] = newInt;
    }
    cout << endl << setw(28) << "Array contents (forward): ";
    for (int i = 0; i < 3; i++){
        cout << pX[i] << ' ';
    }
    cout << endl << setw(28) << "Array contents (backward): ";
    for (int i = 2; i >= 0; i--){
        cout << pX[i] << ' ';
    }
    cout << endl << endl;
    delete pX;


    //PART 2: COMPLETE USING A LINKED LIST
    cout << "Part 2: Using a linked list" << endl;
    Node *pHead = new Node;
    Node *one = new Node;
    Node *two = new Node;

    pHead->pNext = one;
    one->pNext = two;

    Node *n = pHead;
    do {
        cout << setw(28) << "Please enter an integer: ";
        cin >> newInt;
        n->value = newInt;
        n = n->pNext;
    } while (n != nullptr);

    n = pHead;
    cout << endl << setw(28) << "Array contents (forward): ";
    do {
        cout << n->value << ' ';
        n = n->pNext;
    } while (n != nullptr);

    n = pHead;
    cout << endl << setw(28) << "Array contents (backward): ";
    n = n->pNext;
    n = n->pNext;
    cout << n->value << ' ';
    n = pHead->pNext;
    cout << n->value << ' ';
    cout << pHead->value;

    delete pHead;
    delete one;
    delete two;
    delete n;



}