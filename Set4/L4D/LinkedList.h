#include "Node.h"
class LinkedList {
private:
    // Node *makeNodeForValue(const int);
    unsigned int listSize;  
    Node *mMakeNodeForValue (const int);
public:
    Node *pHead;
    Node *pTail;
    LinkedList();
    LinkedList(const LinkedList &object);
    ~LinkedList();
    void pushFront (int);
    void pushBack (int);
    int popFront ();
    int front();
    int back();
    unsigned int size();
    void print();
};
