//
// Created by Álvaro Golbano Durán
//

#ifndef STACKNODE_HPP
#define STACKNODE_HPP
#include <iostream>
#include "User.hpp"
using namespace std;

class StackNode
{
private:
    StackNode *next; //Pointer to the next StackNode
    User element;     //The element of the stackNode
    friend class Stack;
public:
    //Constructors

    StackNode(User stackElem);
    ~StackNode();

    //Access methods

    void setNext(StackNode *stackNext);
    void setElement(User stackElem);

    StackNode *getNext();
    User getElement();
};

#endif //STACKNODE_HPP