/* CSCI 261: Assignment 5: L5A - Double The Fun
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors
 * This program creates a class for Doubly Linked Lists, and performs various functions to validate the functionality of the class.
 */

#include "DoublyLinkedList.hpp"

int main(){

    //Applying values to list in corresponding locations
    DoublyLinkedList<int> intList;
    intList.insert(0, 6);
    intList.insert(0, 5);
    intList.insert(5, 7);
    intList.insert(-3, 1);
    intList.insert(1, 2);
    intList.insert(2, 9);
    intList.insert(2, 3);

    //Print list forward and in reverse
    intList.print();
    intList.printReverse();

    //Change value and print list again
    intList.set(3, 4);
    intList.print();

    //Remove values from positions
    intList.remove(-2);
    intList.remove(9);
    intList.remove(2);

    //Print value at position 2 and size of list
    cout << intList.get(2) << endl;
    cout << intList.size() << endl;

    //Print list forward
    intList.print();

    return 0;
}
