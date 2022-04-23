/* CSCI 261: Assignment 6: L6B - Processing Ordered Lists
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, attempted to learn from youtube videos to no avail
 * This program implements classes for Stack and Queue objects that are linked lists with restrictions on how they can be used, as well as a few tests to ensure that they are implemented properly.
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