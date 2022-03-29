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
    while (n != nullptr){
        next = n->pNext;
        n->pNext = nullptr;
        delete n;
        n = next;
    }
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

LinkedList::LinkedList(const LinkedList &list){
    pHead = new Node();
    pTail = new Node();
    cout << "Copying list..." << endl;
    pHead = list.pHead;
    pTail = list.pTail;
    listSize = size();
}

LinkedList &LinkedList::operator=(const LinkedList& list){
    LinkedList temp(list);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;
}

Node* LinkedList::mMakeNodeForValue (const int VALUE){
    Node *newNode = new Node();           //Allocate space for new node in free store
    newNode->value = VALUE;               //Set value of node
    newNode->pNext = nullptr;             //Set pointer of node to nullptr
    return newNode;                       //Return newly created node
}

void LinkedList::pushFront (const int VALUE) {
    Node *n = mMakeNodeForValue (VALUE);
    listSize = size();
    if (listSize == 0){
        pHead = n;
        pTail = pHead;
    } else if (listSize == 1) {
        pHead = n;
        pHead->pNext = pTail;
    } else {
        n->pNext = pHead;
        pHead = n;
    }
    listSize = size();
}

void LinkedList::pushBack (int VALUE){
    Node *n = mMakeNodeForValue (VALUE);
    listSize = size();
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
    listSize = size();
}

int LinkedList::popFront (){
    if (pHead != nullptr) {
        Node *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        listSize = size();
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
        while (n != pTail) {
            n = n->pNext;
        }
        return n->value;
    }
}

int LinkedList::at(const unsigned int POS){
    if (POS < 0 || POS >= listSize) {
        return T();
    } else {
        Node *n = pHead;
        for (unsigned int i = 0; i < POS; i++){
            n = n->pNext;
        }
        return n->value;
    }
}

unsigned int LinkedList::size() {               
    Node *n = pHead;
    int nCount = 0;
    if (n == nullptr) {
        return 0;
    } else {
        do {
            n = n->pNext;
            nCount++;
        } while (n != pTail->pNext);
        return nCount;
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
        } while (n != pTail->pNext);
        cout << endl;
    }
}

