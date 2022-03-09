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
    LinkedList(const LinkedList &list);
    LinkedList &operator=(const LinkedList &list);
    void pushFront (int);
    void pushBack (int);
    int popFront ();
    int front();
    int back();
    unsigned int size();
    void print();
};
