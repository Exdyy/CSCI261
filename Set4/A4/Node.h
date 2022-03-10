#ifndef NODE_H
#define NODE_H

/**
 * @brief A single element of a linked list containing data to form a vertice
 * 
 */
struct vertNode {
    /**
     * @brief the values of this vertNode
     * 
     */
    float x, y, z;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    vertNode *pNext = nullptr;
};

/**
 * @brief A single element of a linked list containing data to form a face
 * 
 */
struct faceNode {
    /**
     * @brief the values of this faceNode
     * 
     */
    int x, y, z;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    faceNode *pNext = nullptr;
};

#endif