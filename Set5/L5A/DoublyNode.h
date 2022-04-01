#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

/**
 * @brief A single element of a linked list
 * 
 */
struct DoublyNode {
    /**
     * @brief the value of this Node
     * 
     */
    int value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    DoublyNode *pNext = nullptr;
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    DoublyNode *pPrev = nullptr;
};

#endif