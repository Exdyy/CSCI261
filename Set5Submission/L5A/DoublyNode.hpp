/* CSCI 261: Assignment 5: L5A - Double The Fun
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors
 * This program creates a class for Doubly Linked Lists, and performs various functions to validate the functionality of the class.
 */

#ifndef DOUBLYNODE_HPP
#define DOUBLYNODE_HPP

/**
 * @brief A single element of a linked list
 * 
 */
template <typename T>
struct DoublyNode {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    DoublyNode<T> *pNext = nullptr;
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    DoublyNode<T> *pPrev = nullptr;
};

#endif