#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    pHead = new DoublyNode();
    pTail = new DoublyNode();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
    DoublyNode *n = pHead;
    DoublyNode *next = nullptr;
    while (n != nullptr){
        next = n->pNext;
        n->pNext = nullptr;
        n->pPrev = nullptr;
        delete n;
        n = next;
    }
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &OTHER){
    pHead = new DoublyNode();
    pTail = new DoublyNode();
    cout << "Copying list..." << endl;
    pHead = OTHER.pHead;
    pTail = OTHER.pTail;
    listSize = size();
}

DoublyLinkedList &DoublyLinkedList::operator=(const DoublyLinkedList& OTHER){
    DoublyLinkedList temp(OTHER);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;
}

DoublyNode* DoublyLinkedList::mMakeNodeForValue (const int VALUE){
    DoublyNode *newNode = new DoublyNode();           //Allocate space for new node in free store
    newNode->value = VALUE;               //Set value of node
    newNode->pNext = nullptr;             //Set pointer of node to nullptr
    newNode->pPrev = nullptr;
    return newNode;                       //Return newly created node
}

void DoublyLinkedList::pushFront (const int VALUE) {
    DoublyNode *n = mMakeNodeForValue (VALUE);
    listSize = size();
    if (listSize == 0){
        pHead = n;
        pTail = pHead;
    } else if (listSize == 1) {
        pHead = n;
        pHead->pNext = pTail;
        pTail->pPrev = pHead;
    } else {
        n->pNext = pHead;
        pHead->pPrev = n;
        pHead = n;
    }
    listSize = size();
}

void DoublyLinkedList::pushBack (int VALUE){
    DoublyNode *n = mMakeNodeForValue (VALUE);
    listSize = size();
    if (listSize == 0){
        pHead = n;
        pTail = pHead;
    } else if (listSize == 1){
        pTail = n;
        pHead->pNext = pTail;
        pTail->pPrev = pHead;
    } else {
        pTail->pNext = n;
        n.pPrev = pTail;
        pTail = n;
    }
    listSize = size();
}

int DoublyLinkedList::popFront (){
    if (pHead != nullptr) {
        DoublyNode *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        pHead->pPrev = nullptr;
        temp->pNext = nullptr;
        listSize = size();
        return frontVal;
    } else {
        return -1;
    } 
}

int DoublyLinkedList::front(){
    if (pHead != nullptr) {
        return pHead->value;
    } else {
        return -1;
    }
}

int DoublyLinkedList::back(){
    if (pHead == nullptr) {
        return -1;
    } else {
        DoublyNode *n = pHead;
        while (n != pTail) {
            n = n->pNext;
        }
        return n->value;
    }
}

unsigned int DoublyLinkedList::size() {               
    DoublyNode *n = pHead;
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

void DoublyLinkedList::print(){
    DoublyNode *n = pHead;
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

void DoublyLinkedList::print(){
    DoublyNode *n = pTail;
    if (pHead == nullptr){
        cout << "Empty list" << endl;
    } else { 
        cout << "Backwards List contents: ";
        do {
            cout << n->value << ' ';
            n = n->pPrev;
        } while (n != pHead->pPrev);
        cout << endl;
    }
}

