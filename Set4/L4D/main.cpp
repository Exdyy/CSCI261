#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList myList;
    myList.pushFront(3);
    myList.pushFront(2);
    myList.pushFront(1);
    myList.pushFront(0);

    // cout << "Size: " << myList.size() << endl;
    cout << myList.front() << endl;
    cout << myList.back() << endl;

    cout << myList.popFront() << endl;
    cout << myList.front();
    myList.print();
    myList.~LinkedList();

    return 0;
}