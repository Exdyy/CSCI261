#include "DoublyNode.hpp"
#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    unsigned int listSize;  
    DoublyNode<T> *mMakeNodeForValue (const T);
    DoublyNode<T> *pHead;
    DoublyNode<T> *pTail;
public:
    DoublyLinkedList<T>();
    ~DoublyLinkedList<T>();
    DoublyLinkedList(const DoublyLinkedList<T> &list);
    DoublyLinkedList &operator=(const DoublyLinkedList<T> &list);
    void pushFront (T);
    void pushBack (T);
    T popFront ();
    T front();
    T back();
    T get(const unsigned int);
    void set(const int POS, const T);
    void insert(const int, const T);
    void remove(const int POS);
    unsigned int size();
    void print();
    void printReverse();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    pHead = new DoublyNode<T>();
    pTail = new DoublyNode<T>();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
    cout << "LIST CONSTRUCTED" << endl;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    DoublyNode<T> *n = pHead;
    DoublyNode<T> *next = nullptr;
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
    cout << "LIST DESTRUCTED" << endl;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &OTHER){
    pHead = new DoublyNode<T>();
    pTail = new DoublyNode<T>();
    cout << "Copying list..." << endl;
    pHead = OTHER.pHead;
    pTail = OTHER.pTail;
    listSize = size();
}

template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& OTHER){
    DoublyLinkedList<T> temp(OTHER);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;
}

template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::mMakeNodeForValue (const T VALUE){
    DoublyNode<T> *newNode = new DoublyNode<T>();     //Allocate space for new DoublyNode<T> in free store
    newNode->value = VALUE;               //Set value of DoublyNode<T>
    newNode->pNext = nullptr;             //Set pointer of DoublyNode<T> to nullptr
    newNode->pPrev = nullptr;
    return newNode;                       //Return newly created DoublyNode<T>
}

template <typename T>
void DoublyLinkedList<T>::pushFront (const T VALUE) {
    DoublyNode<T> *n = mMakeNodeForValue(VALUE);
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

template <typename T>
void DoublyLinkedList<T>::pushBack (T VALUE){
    DoublyNode<T> *n = mMakeNodeForValue (VALUE);
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
        n->pPrev = pTail;
        pTail = n;
    }
    listSize = size();
}

template <typename T>
T DoublyLinkedList<T>::popFront (){
    if (pHead != nullptr) {
        DoublyNode<T> *temp = pHead;
        int frontVal = temp->value;
        pHead = pHead->pNext;
        temp->pNext = nullptr;
        temp->value = NULL;
        pHead->pPrev = nullptr;
        listSize = size();
        delete temp;
        return frontVal;
    } else {
        return T();
    } 
}

template <typename T>
T DoublyLinkedList<T>::front(){
    if (pHead != nullptr) {
        return pHead->value;
    } else {
        return T();
    }
}

template <typename T>
T DoublyLinkedList<T>::back(){
    if (pHead == nullptr) {
        return T();
    } else {
        return pTail->value;
    }
}

template <typename T>
T DoublyLinkedList<T>::get(const unsigned int POS){
    if (POS < 0 || POS >= listSize) {
        return T();
    } else {
        DoublyNode<T> *n = pHead;
        for (unsigned int i = 0; i < POS; i++){
            n = n->pNext;
        }
        return n->value;
    }
}

template <typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL){
    if (POS >= 0 && POS < (int)listSize) {
        DoublyNode<T> *n = pHead;
        for (int i = 0; i < POS; i++){
            n = n->pNext;
        }
        n->value = VAL;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL){
    DoublyNode<T> *n = pHead;
    if (POS <= 0){
        pushFront(VAL);
    } else if (POS >= (int)listSize){
        pushBack(VAL);
    } else {
        for (int i = 0; i < POS; i++) {
            n = n->pNext;
        }
        DoublyNode<T> *prev = n->pPrev;
        DoublyNode<T> *newNode = mMakeNodeForValue(VAL);
        newNode->pNext = n;
        newNode->pPrev = prev;
        n->pPrev = newNode;
        prev->pNext = newNode;
    }
    listSize = size();
}
template <typename T>
void DoublyLinkedList<T>::remove(const int POS) {
    DoublyNode<T> *temp = pHead;
    if (POS < 0) {
        pHead = pHead->pNext;
        temp->pNext = nullptr;
        temp->pPrev = nullptr;
        pHead->pPrev = nullptr;
    } else if (POS >= (int)listSize){
        temp = pTail;
        pTail = pTail->pPrev;
        temp->pNext = nullptr;
        temp->pPrev = nullptr;
        pTail->pNext = nullptr;
    } else {
        temp = pHead;
        for (int i = 0; i < POS; i++){
            temp = temp->pNext;
        }
        DoublyNode<T> *prev = temp->pPrev;
        DoublyNode<T> *next = temp->pNext;
        temp->pNext = nullptr;
        temp->pPrev = nullptr;
        prev->pNext = next;
        next->pPrev = prev;
    }
    listSize = size();
}

template <typename T>
unsigned int DoublyLinkedList<T>::size() {               
    DoublyNode<T> *n = pHead;
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

template <typename T>
void DoublyLinkedList<T>::print(){
    DoublyNode<T> *n = pHead;
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

template <typename T>
void DoublyLinkedList<T>::printReverse(){
    DoublyNode<T> *n = pTail;
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
