#include "Node.h"
class LinkedList {

    public:
    Node *pHead;
    Node *pTail;
    unsigned int size;    
};

Node *makeNodeForValue (int);

void pushFront (int);

void pushBack (int);

void popFront ();