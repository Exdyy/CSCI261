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
    int *pX = new int[3];           //Allocate space for an array of size 3
    for (int i = 0; i < 3; i++){    //Loop through array
        cout << setw(28) << "Please enter an integer: ";
        cin >> newInt;              //Get user input
        pX[i] = newInt;             //Set array elements to user Input
    }
    cout << endl << setw(28) << "Array contents (forward): ";
    for (int i = 0; i < 3; i++){    //Loop and print contents of array forward (elements 0,1,2)
        cout << pX[i] << ' ';
    }
    cout << endl << setw(28) << "Array contents (backward): ";
    for (int i = 2; i >= 0; i--){   //Loop and print contents of array backward (elements 2,1,0)
        cout << pX[i] << ' ';
    }
    cout << endl << endl;
    delete pX;                      //Deallocate memory in free store


    //PART 2: COMPLETE USING A LINKED LIST
    cout << "Part 2: Using a linked list" << endl;
    Node *pHead = new Node;         //Create node for each value in array (3 nodes)
    Node *one = new Node;
    Node *two = new Node;

    pHead->pNext = one;             //Link node pHead to point to node one
    one->pNext = two;               //Link node one to point to node two

    Node *n = pHead;                //Node n used to step through linked list
    do {
        cout << setw(28) << "Please enter an integer: ";
        cin >> newInt;              //Ask user for integers
        n->value = newInt;          //Set node value = user input
        n = n->pNext;               //Step to next node
    } while (n != nullptr);         //Stop when at last node

    n = pHead;                      //Place n back at beginning of linked list, pHead
    cout << endl << setw(28) << "Array contents (forward): ";
    do {
        cout << n->value << ' ';    //Output content of node
        n = n->pNext;               //Step to next node
    } while (n != nullptr);         //Stop when at last nodes

    n = pHead;                      //Place n back to beginning of linked list, pHead
    cout << endl << setw(28) << "Array contents (backward): ";
    n = n->pNext;                   //Step to node one
    n = n->pNext;                   //Step to node two
    cout << n->value << ' ';        //Output value of node two
    n = pHead->pNext;               //place n at node one
    cout << n->value << ' ';        //Output value of node one
    cout << pHead->value;           //Output value of node pHead
                                    //Array is printed in reverse in lines 60-65
    delete pHead;                   //Free up space in free store by deleting all created nodes
    delete one;
    delete two;
    delete n;



}