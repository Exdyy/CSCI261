#include "Node.h"
class LinkedList {
public:
    //ATTRIBUTES
    Node *pHead;
    Node *pTail;
    unsigned int size;  

    //BEHAVIOURS
    Node *makeNodeForValue (int);
    void pushFront (int);
    void pushBack (int);
    void popFront ();
};
