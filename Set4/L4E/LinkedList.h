#include "Node.h"
class LinkedList {
private:
    unsigned int listSize;  
    Node *mMakeNodeForValue (const int);
    Node *pHead;
    Node *pTail;
public:
    LinkedList();
    ~LinkedList();
    void pushFront (int);
    void pushBack (int);
    int popFront ();
    int front();
    int back();
    unsigned int size();
    void print();
};
