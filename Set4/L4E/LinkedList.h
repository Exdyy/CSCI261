#include "Node.h"
class LinkedList {
private:
    Node *pHead;
    Node *pTail;
    // Node *makeNodeForValue(const int);
    unsigned int listSize;  
    Node *mMakeNodeForValue (const int);
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
