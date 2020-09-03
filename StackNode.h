//
// Created by Álvaro Golbano Durán
//

#ifndef STACKNODE_H
#define STACKNODE_H
#include "User.h"

class StackNode
{
private:
    StackNode *next; //Pointer to the next StackNode
    User element;    //The element of the stackNode
public:
    //Constructor and destructor
    StackNode(User stackElem);
    ~StackNode();

    //Access methods

    void setNext(StackNode *stackNext);
    void setElement(User stackElem);
    StackNode *getNext();
    User getElement();
};

#endif // STACKNODE_H
