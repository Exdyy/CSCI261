#include "vertList.h"
#include <iostream>
using namespace std;

vertList::vertList(){
    pHead = new vertNode();
    pTail = new vertNode();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

vertList::~vertList(){
    vertNode *n = pHead;
    vertNode *next = nullptr;
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

vertList::vertList(const vertList &list){
    pHead = new vertNode();
    pTail = new vertNode();
    cout << "Copying list..." << endl;
    pHead = list.pHead;
    pTail = list.pTail;
    listSize = size();
}
vertList &vertList::operator=(const vertList& list){
    vertList temp(list);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;}

vertNode* vertList::mMakeNodeForValue (float x, float y, float z){
    vertNode *newNode = new vertNode();             //Allocate space for new node in free store
    newNode->xVal = x;                              //Set value of node
    newNode->pNext = nullptr;                       //Set pointer of node to nullptr
    return newNode;                                 //Return newly created node}

void vertList::pushFront (float xVal, float yVal, float zVal) {
    vertNode *n = mMakeNodeForValue (float xVal, float yVal, float zVal);
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
    listSize = size();}

void vertList::pushBack (int VALUE){
    vertNode *n = mMakeNodeForValue (VALUE);
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
    listSize = size();}

int vert
List::popFront (){
    if (pHead != nullptr) {
        vertNode *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        listSize = size();
        return frontVal;
    } else {
        return -1;
    } }

int vert
List::front(){
    if (pHead != nullptr) {
        return pHead->value;
    } else {
        return -1;
    }}

int vert
List::back(){
    if (pHead == nullptr) {
        return -1;
    } else {
        vertNode *n = pHead;
        while (n != pTail) {
            n = n->pNext;
        }
        return n->value;
    }}

unsigned int vert
List::size() {               
    vertNode *n = pHead;
    int nCount = 0;
    if (n == nullptr) {
        return 0;
    } else {
        do {
            n = n->pNext;
            nCount++;
        } while (n != pTail->pNext);
        return nCount;
    }}

void vert
List::print(){
    vertNode *n = pHead;
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

