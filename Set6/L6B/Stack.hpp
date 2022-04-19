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
    pHead = nullptr;
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
    listSize = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &list){
    pHead = new Node<T>();
    cout << "Copying list..." << endl;
    pHead = list.pHead;
    listSize = size();
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T>& list){
    Stack<T> temp(list);
    swap(temp.pHead, pHead);
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
    } else if(listSize == 1){
        n = pHead->pNext;
    } else {
        Node<T> *temp = new Node<T>;
        temp = pHead;
        for (int i = 0; i < listSize; i++){
            temp = temp->pNext;
        }
        temp->pNext = n;
        pHead = n;
        delete temp;
    }
    listSize = size();
}

template <typename T>
T Stack<T>::pop (){
    if (pHead != nullptr) {
        Node<T> *temp = new Node<T>;
        temp  = pHead;
        while (temp->pNext != nullptr){
            temp = temp->pNext;
        }
        int backVal = temp->value;
        return backVal;
    } else {
        return T();
    } 
}

template <typename T>
T Stack<T>::peak(){
    if (pHead != nullptr) {
        return pHead->value;
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
        } while (n != nullptr);
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
        } while (n != nullptr);
        cout << endl;
    }
}

template <typename T>
bool Stack<T>::isEmpty(){
    if (pHead == NULL){
        return true;
    } else {
        return false;
    }
}