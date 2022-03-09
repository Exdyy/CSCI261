#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    LinkedList list1;
    cout << "**** list1 ****" << endl;
    cout << "list1 Initial Size: " << list1.size() << endl;
    list1.pushFront(1);
    list1.pushBack(2);
    list1.pushFront(3);
    list1.pushBack(4);
    list1.pushFront(5);
    list1.pushBack(6);
    cout << "list1 Modified Size: " << list1.size() << endl;
    list1.print(); 
    cout << endl;

    LinkedList list2;
    cout << "list2 Initial Size: " << list2.size() << endl;
    list2 = list1;
    cout << "list2 Modified Size: " << list2.size() << endl;
    cout << "list1 Modified Size: " << list1.size() << endl;
    cout << "list2 - ";
    list2.print(); 
    cout << endl;

    cout << "Adding values to list1..." << endl;
    list1.pushFront(7);
    list1.pushBack(8);

    cout << "Sizes: " << list1.size() << ' ' << list2.size() << endl;
    cout << "list1 - ";
    list1.print();
    cout << "list2 - ";
    list2.print();
    cout << endl;

    cout << "Creating list3 as a copy of list1..." << endl;
    LinkedList list3(list1);
    cout << "Sizes: " << list1.size() << ' ' << list2.size() << ' ' << list3.size() << endl;
    cout << endl;
    cout << "Adding values to list1..." << endl;
    list1.pushFront(9);
    list1.pushBack(10);

    cout << "Sizes again: " << list1.size() << ' ' << list2.size() << ' ' << list3.size() << endl;
    cout << "list1 - "; list1.print();
    cout << "list2 - "; list2.print();
    cout << "list3 - "; list3.print();
}
