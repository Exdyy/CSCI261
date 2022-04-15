/* CSCI 261: Assignment 5: L5D - Sorting II & Recursion II: Merge Sort via the Call Stack
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, https://www.interviewkickstart.com/learn/merge-sort-for-linked-list
 * This program is supposed to perform a merge sort on a linked list, but I have tried for way too many hours and still cannot get this to work, so here is my final attempt for now.
 */

#include "LinkedList.hpp"
#include <iostream>
using namespace std;

template<typename T>
void split(Node<T>* head, Node<T>** head1, Node<T>** head2){
    // Node<T>* temp = head;
    // int nodeCount = 0;
    // while (temp!=NULL){
    //     temp = temp->pNext;
    //     nodeCount++;
    // }
    // int halfPoint = nodeCount / 2;
    // temp = head;
    // for (int i = 0; i < halfPoint; i++){
    //     temp = temp->pNext;
    // }

    // *head1 = head;           //Assign head1 to head of first half
    // *head2 = temp->pNext;    //Assign head2 to head of second half
    // temp->pNext = nullptr;  //Split list by breaking node connections

    if (head->pNext == nullptr){
        return;
    }
    Node<T>* fast = head->pNext;
    Node<T>* slow = head;
    while (fast != nullptr){
        fast = fast->pNext;         //fast node progresses twice per loop
        if (fast != nullptr) {
            fast = fast->pNext;
            slow = slow->pNext;     //slow node progresses once per loop, marking halfway point once fast reaches the end
        }
    }
    *head1 = head;                  //First half starts at head node
    *head2 = slow->pNext;           //Second half starts one node after slow node
    slow->pNext = nullptr;          //Split the two lists
}

template<typename T>
Node<T>* merge(Node<T>* head1, Node<T>* head2){
    Node<T>* temp = NULL;
    if (head1 == NULL){
        return head2;
    } else if (head2 == NULL){
        return head1;
    } else {
        if (head2->value > head1->value){
            temp = head1;
            temp->pNext = merge(head1->pNext, head2);
        } else {
            temp = head2;
            temp->pNext = merge(head1, head2->pNext);
        }
    }
    return temp;
}

template<typename T>
void mergeSort(Node<T>** head){
    Node<T>* sortedHead = *head;
    Node<T>* head1;
    Node<T>* head2;
    if (sortedHead == nullptr){
        return;
    }
    if (sortedHead->pNext == nullptr){
        return;
    }
    split(*head, &head1, &head2);
    mergeSort(&head1);
    mergeSort(&head2);
    *head = merge(head1, head2);
    return;
}

int main(){
    LinkedList<int> list;

    list.pushBack(4);
    list.pushBack(3);
    list.pushBack(8);
    list.pushBack(1);
    list.pushBack(5);
    list.pushBack(9);
    list.pushBack(7);
    list.pushBack(2);
    list.pushBack(6);

    list.print();
    Node<int> *head = list.pHead;
    mergeSort(&head);
    list.print();
}