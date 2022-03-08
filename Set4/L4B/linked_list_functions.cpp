#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
    Node *n = new Node();           //Allocate space for new node in free store
    n->value = VALUE;               //Set value of node
    n->pNext = nullptr;             //Set pointer of each node to nullptr
    return n;                       //Return newly created node
}

int linked_list_get_size(Node* pHead) {
    Node* n = pHead;                //Set node to point to pHead
    int nodeCount = 0;              //Initialize counter for number of nodes
    if (pHead == nullptr){          //Check to see if linked list is empty, return 0 if so
        return 0;                   
    } else {            
        do {
            n = n->pNext;           //Step to next node pointed to by previous node
            nodeCount++;            //Increment counter to track # of nodes
        } while ( n != nullptr );   //Stop when node is empty
        return nodeCount;           //Return int for number of nodes found
    }
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
    Node* newHead = linked_list_make_node(VALUE);   //Create new node with certain value
    newHead->pNext = pHead;                         //Set pNext to point to pHead, transforming newHead into the first node in the linked list

    return newHead;                                 //Return newHead node
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    Node* n = pHead;
    if (linked_list_get_size(pHead) <= POS || POS < 0) {    //Check if position is out of range of current list, return -1 if so
        return -1;      
    } else if (POS == 0){                                   //If position = 0, return first element of list (pHead->value)
        return n->value;
    } else {                                                
        int i = 0;
        do {                                                //Position in range, and != 0, step through list to element [POS]
            n = n->pNext;                                   //Step to next node
            i++;                                            //Increment counter
        } while (i < POS);                                  //Stop when i == POS
    }
    return n->value;                                        //Return value at requested position
}

int linked_list_min(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr) {             //Check if list is empty, return -1 if so
        return -1;
    } else {
        int min = pHead->value;     //Initialize min with first value in list
        do {
            if (n->value < min){    //Check for smaller values
                min = n->value;     //If found, set min = smallest value found
            }
            n = n->pNext;           //Step to next node
            
        } while ( n != nullptr );   //Stop when no nodes left to check
        return min;                 //Return minimum value
    }
}

int linked_list_max(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr) {             //Check if list is empty, return -1 if so
        return -1;
    } else {
        int max = pHead->value;     //Initialize max with first value in list
        do {
            if (n->value > max){    //Check for larger values
                max = n->value;     //If found, set max = largest value found
            }
            n = n->pNext;           //Step to next node
            
        } while ( n != nullptr );   //Stop when no nodes left to check
        return max;                 //Return maximum value
    }
}

int linked_list_find(Node* pHead, const int TARGET) {
    Node* n = pHead;
    bool found = false;                     //Boolean to signify when target value is found
    int index = 0;
    int size = linked_list_get_size(pHead); //Find size to check if list is empty
    while (found == false){
        if (index == size){                 //If size == 0, empty list, return -1. Or...
            return -1;                      //If not empty, when index == size, target is out of bounds of the linked list and wasn't found, return -1
        } else if (n->value != TARGET){     //Compare node value to target value
            n = n->pNext;                   //Step to next if value!=target
            index++;                        //Increment index
        } else {
            found = true;                   //Switch boolean to true to signify that target value was found at index
        }
    }
    return index;                           //Return index of found value
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    Node* n = pHead;
    if (n == nullptr){      //Check for empty list
        return nullptr;     //Return null if empty
    } else{
        n = n->pNext;       //Set n == pointer of second node
        pHead->pNext = nullptr;       
        delete pHead;       //Free up space from previous pHead node
        pHead = n;          //Assign pHead to new first node, n
        return pHead;       //Return pHead node
    }
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    Node* n = pHead;
    if (linked_list_get_size(pHead) <= POS || POS < 0) {    //Check to see if position is out of range
        return pHead;                                       //If so, return pHead, leave list unmodified
    } else if (POS == 0){       //If position == 0, return value at head
        n->value = VALUE;
    } else {                    //If position is not 0:
        int i = 0;              //Initialize counter
        do {
            n = n->pNext;       //Step through nodes
            i++;                //Increment counter to track which node program is at
        } while (i < POS);      //Stop when counter == POS
        n->value = VALUE;       //Change current node's value to VALUE provided in function arguments
    }
    return pHead;               //Return pHead, with modified value
}