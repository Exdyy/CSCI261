#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
    Node *n = new Node();
    n->value = VALUE;
    n->pNext = nullptr;
    return n;
}

int linked_list_get_size(Node* pHead) {
    Node* n = pHead;
    int nodeCount = 0;
    if (pHead == nullptr){
        return 0;
    } else {
        do {
            n = n->pNext;
            nodeCount++;
        } while ( n != nullptr );
        return nodeCount;
    }
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
    Node* newHead = linked_list_make_node(VALUE);
    newHead->pNext = pHead;

    return newHead;
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    Node* n = pHead;
    if (linked_list_get_size(pHead) <= POS || POS < 0) {
        return -1;
    } else if (POS == 0){
        return n->value;
    } else {
        int i = 0;
        do {
            n = n->pNext;
            i++;
        } while (i < POS);
    }
    return n->value;
}

int linked_list_min(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr) {
        return -1;
    } else {
        int min = pHead->value;
        do {
            if (n->value < min){
                min = n->value;
            }
            n = n->pNext;
            
        } while ( n != nullptr );
        return min;
    }
}

int linked_list_max(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr) {
        return -1;
    } else {
        int max = pHead->value;
        do {
            if (n->value > max){
                max = n->value;
            }
            n = n->pNext;
            
        } while ( n != nullptr );
        return max;
    }
}

int linked_list_find(Node* pHead, const int TARGET) {
    Node* n = pHead;
    bool found = false;
    int index = 0;
    int size = linked_list_get_size(pHead);
    while (found == false){
        if (index == size){
            return -1;
        } else if (n->value != TARGET){
            n = n->pNext;
            index++;
        } else {
            found = true; 
        }
    }
    return index;
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr){
        return nullptr;
    } else{
        n = n->pNext;
        pHead = n;
        return pHead;
    }
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    Node* n = pHead;
    if (linked_list_get_size(pHead) <= POS || POS < 0) {
        return pHead;
    } else if (POS == 0){
        n->value = VALUE;
    } else {
        int i = 0;
        do {
            n = n->pNext;
            i++;
        } while (i < POS);
        n->value = VALUE;
    }
    return pHead;
}