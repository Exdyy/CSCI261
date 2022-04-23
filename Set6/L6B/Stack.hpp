/* CSCI 261: Assignment 6: L6B - Processing Ordered Lists
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, attempted to learn from youtube videos to no avail
 * This program implements classes for Stack and Queue objects that are linked lists with restrictions on how they can be used, as well as a few tests to ensure that they are implemented properly.
 */

#include "Node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    unsigned int listSize;  
    Node<T> *mMakeNodeForValue (const T);
public:
    Node<T> *pHead;
    Node<T> *pTail;
    Stack<T>();
    ~Stack<T>();
    Stack(const Stack<T> &list);
    Stack &operator=(const Stack<T> &list);
    void push (T);
    T pop ();
    T peak();
    T at(const unsigned int);
    unsigned int size();
    void print();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack(){
    pHead = new Node<T>();
    pTail = new Node<T>();
    pHead = nullptr;
    pTail = nullptr;
    listSize = 0;
}

template <typename T>
Stack<T>::~Stack(){
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
Stack<T>::Stack(const Stack<T> &list){
    pHead = new Node<T>();
    pTail = new Node<T>();
    cout << "Copying list..." << endl;
    pHead = list.pHead;
    pTail = list.pTail;
    listSize = size();
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T>& list){
    Stack<T> temp(list);
    swap(temp.pHead, pHead);
    swap(temp.pTail, pTail);
    swap(temp.listSize, listSize);
    return *this;
}

template <typename T>
Node<T>* Stack<T>::mMakeNodeForValue (const T VALUE){
    Node<T> *newNode = new Node<T>();     //Allocate space for new Node<T> in free store
    newNode->value = VALUE;               //Set value of Node<T>
    newNode->pNext = nullptr;             //Set pointer of Node<T> to nullptr
    return newNode;                       //Return newly created Node<T>
}

template <typename T>
void Stack<T>::push (T VALUE){
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
T Stack<T>::pop (){
    if (listSize == 0){
        return T();
    } else if (listSize == 1){
        listSize--;
        return pHead->value;
    } else {
        Node<T> *back = pHead->pNext;
        Node<T> *newBack = pHead;
        while (back->pNext != nullptr){
            back = back->pNext;
            newBack = newBack->pNext;
        }
        T value = back->value;
        back->value = T();
        newBack->pNext = nullptr;
        listSize--;
        return value;
    }
}

template <typename T>
T Stack<T>::peak(){
    if (pHead != nullptr) {
        Node<T> *temp = pHead;
        while (temp->pNext != nullptr) {
            temp = temp->pNext;
        }
        return temp->value;
    } else {
        return T();
    }
}

template <typename T>
T Stack<T>::at(const unsigned int POS){
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
unsigned int Stack<T>::size() {                
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
void Stack<T>::print(){
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

template <typename T>
bool Stack<T>::isEmpty(){
    if (listSize == 0){
        return true;
    } else {
        return false;
    }
}