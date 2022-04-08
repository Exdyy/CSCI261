#include "DoublyLinkedList.hpp"

int main(){
    DoublyLinkedList<int> intList;
    intList.insert(0, 6);
    intList.insert(0, 5);
    intList.insert(5, 7);
    intList.insert(-3, 1);
    intList.insert(1, 2);
    intList.insert(2, 9);
    intList.insert(2, 3);
    intList.print();
    intList.printReverse();
    intList.set(3, 4);
    intList.print();
    intList.remove(-2);
    intList.remove(9);
    intList.remove(2);
    cout << intList.get(2) << endl;
    cout << intList.size() << endl;
    intList.print();
    intList.~DoublyLinkedList<int>();

    return 0;
}
