/* CSCI 261: Assignment 6: L6B - Processing Ordered Lists
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, attempted to learn from youtube videos to no avail
 * This program implements classes for Stack and Queue objects that are linked lists with restrictions on how they can be used, as well as a few tests to ensure that they are implemented properly.
 */

#include "Stack.hpp"
#include "Queue.hpp"

#include <iostream>
using namespace std;

int main() {
    Stack<int> stacker;
    stacker.push(1);
    stacker.push(2);
    stacker.push(3);
    stacker.push(4);
    stacker.push(5);
    while( !stacker.isEmpty() ) {
        cout << "stack top is: " << stacker.peak() << " \t";
        int top = stacker.pop();
        cout << "stack top was: " << top << endl;
    }
    cout << "stack is empty" << endl;

    cout << endl;

    Queue<int> queuer;
    queuer.push(1);
    queuer.push(2);
    queuer.push(3);
    queuer.push(4);
    queuer.push(5);
    while( !queuer.isEmpty() ) {
        cout << "queue front is: " << queuer.peak() << "\t";
        int front = queuer.pop();
        cout << "queue front was: " << front << endl;
    }
    cout << "queue is empty" << endl;

    return 0;
}