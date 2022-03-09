#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    Node *pHead = new Node();
    pHead = nullptr;
    Node *pTail = new Node();
    pTail = nullptr;
    listSize = 0;
}

LinkedList::~LinkedList(){
    Node *n = pHead;
    Node *next = nullptr;
    while (n != nullptr){
        next = n->pNext;
        delete n;
        n = next;
    }
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

Node* LinkedList::mMakeNodeForValue (const int VALUE){
    Node *n = new Node();           //Allocate space for new node in free store
    n->value = VALUE;               //Set value of node
    n->pNext = nullptr;             //Set pointer of node to nullptr
    return n;                       //Return newly created node
}

void LinkedList::pushFront (const int VALUE) {
    Node *n = mMakeNodeForValue (VALUE);
    n->pNext = pHead;
    pHead = n;
}

void LinkedList::pushBack (int VALUE){
    Node *n = mMakeNodeForValue (VALUE);
    pTail->pNext = n;
    pTail = n;
}

int LinkedList::popFront (){
    if (pHead != nullptr) {
        Node *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        return frontVal;
    } else {
        return -1;
    }
}

int LinkedList::front(){
    if (pHead != nullptr) {
        return pHead->value;
    } else {
        return -1;
    }
}

int LinkedList::back(){
    if (pHead == nullptr) {
        return -1;
    } else {
        Node *n = pHead;
        while (n->pNext != nullptr) {
            n = n->pNext;
        }
        return n->value;
    }
}

unsigned int LinkedList::size() {
    Node* n = pHead;                    //Set node to point to pHead
    if (pHead != nullptr){              //Check to see if linked list is empty, return 0 if so
        int nodeCount = 1;              //Initialize counter for number of nodes
        while (n != nullptr) {
            n = n->pNext;               //Step to next node in list
            nodeCount++;                //Incremement node counter
        }   
        return nodeCount;               //Return int for number of nodes found
    } else {            
        return 0;                   
    }
}

void LinkedList::print(){
    Node *n = pHead;
    if (pHead == nullptr){
        cout << "Empty list" << endl;
    } else { 
        cout << "List contents: ";
        do {
            cout << n->value << ' ';
            n = n->pNext;
        } while (n != nullptr);
        cout << endl;
    }
}