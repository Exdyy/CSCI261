#include "Node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    unsigned int listSize;  
    Node<T> *mMakeNodeForValue (const T);
public:
    Node<T> *pHead;
    Node<T> *pTail;
    LinkedList<T>();
    ~LinkedList<T>();
    LinkedList(const LinkedList<T> &list);
    LinkedList &operator=(const LinkedList<T> &list);
    void pushFront (T);
    void pushBack (T);
    T popFront ();
    T front();
    T back();
    T at(const unsigned int);
    unsigned int size();
    void print();
};

template <typename T>
LinkedList<T>::LinkedList(){
    pHead = new Node<T>();
    pTail = new Node<T>();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T> *n = pHead;
    Node<T> *next = nullptr;
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

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    pHead = new Node<T>();
    pTail = new Node<T>();
    cout << "Copying list..." << endl;
    pHead = list.pHead;
    pTail = list.pTail;
    listSize = size();
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T>& list){
    LinkedList<T> temp(list);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;
}

template <typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue (const T VALUE){
    Node<T> *newNode = new Node<T>();     //Allocate space for new Node<T> in free store
    newNode->value = VALUE;               //Set value of Node<T>
    newNode->pNext = nullptr;             //Set pointer of Node<T> to nullptr
    return newNode;                       //Return newly created Node<T>
}

template <typename T>
void LinkedList<T>::pushFront (const T VALUE) {
    Node<T> *n = mMakeNodeForValue(VALUE);
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

template <typename T>
void LinkedList<T>::pushBack (T VALUE){
    Node<T> *n = mMakeNodeForValue (VALUE);
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

template <typename T>
T LinkedList<T>::popFront (){
    if (pHead != nullptr) {
        Node<T> *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        listSize = size();
        return frontVal;
    } else {
        return T();
    } 
}

template <typename T>
T LinkedList<T>::front(){
    if (pHead != nullptr) {
        return pHead->value;
    } else {
        return T();
    }
}

template <typename T>
T LinkedList<T>::back(){
    if (pHead == nullptr) {
        return T();
    } else {
        Node<T> *n = pHead;
        while (n != pTail) {
            n = n->pNext;
        }
        return n->value;
    }
}

template <typename T>
T LinkedList<T>::at(const unsigned int POS){
    if (POS < 0 || POS >= listSize) {
        return T();
    } else {
        Node<T> *n = pHead;
        for (unsigned int i = 0; i < POS; i++){
            n = n->pNext;
        }
        return n->value;
    }
}

template <typename T>
unsigned int LinkedList<T>::size() {               
    Node<T> *n = pHead;
    int nCount = 0;
    if (n == NULL) {
        return 0;
    } else {
        do {
            n = n->pNext;
            nCount++;
        } while (n != pTail->pNext);
        return nCount;
    }
}

template <typename T>
void LinkedList<T>::print(){
    Node<T> *n = pHead;
    if (pHead == NULL){
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
