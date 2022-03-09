#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList myList;
    cout << "Size: " << myList.size() << endl;
    myList.pushFront(1);
    myList.pushBack(2);
    myList.pushFront(3);
    myList.pushBack(4);
    myList.pushFront(5);
    myList.pushBack(6);
    myList.size();
    myList.print();
}
