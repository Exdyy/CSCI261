/* CSCI 261: Assignment 5: L5D - Sorting II & Recursion II: Merge Sort via the Call Stack
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, https://www.interviewkickstart.com/learn/merge-sort-for-linked-list
 * This program is supposed to perform a merge sort on a linked list, but I have tried for way too many hours and still cannot get this to work, so here is my final attempt for now.
 */
#ifndef NODE_H
#define NODE_H

/**
 * @brief A single element of a linked list
 * 
 */
template <typename T>
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node<T> *pNext = nullptr;
};

#endif