#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    pHead = new Node();
    pTail = new Node();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

LinkedList::~LinkedList(){
    Node *n = pHead;
    Node *next = nullptr;
    do {
        next = n->pNext;
        n->pNext = nullptr;
        delete n;
        n = next;
    } while (n != nullptr);
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

Node* LinkedList::mMakeNodeForValue (const int VALUE){
    Node *newNode = new Node();           //Allocate space for new node in free store
    newNode->value = VALUE;               //Set value of node
    newNode->pNext = nullptr;             //Set pointer of node to nullptr
    return newNode;                       //Return newly created node
}

void LinkedList::pushFront (const int VALUE) {
    Node *n = mMakeNodeForValue (VALUE);
    n->pNext = pHead;
    pHead = n;
    if (listSize == 0){
        pTail = pHead;
    }
    listSize++;
    delete n;
}

void LinkedList::pushBack (int VALUE){
    Node *n = mMakeNodeForValue (VALUE);
    if (listSize == 0){
        pHead = n;
        pTail = pHead;
    } else if (listSize == 1){
        pTail = n;
        pHead->pNext = pTail;
    } else {
        pTail->pNext = n;
        pTail = n;
    }
    listSize++;
}

int LinkedList::popFront (){
    if (pHead != nullptr) {
        Node *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        listSize--;
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
    return listSize;
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