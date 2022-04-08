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