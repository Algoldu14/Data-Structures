//
// Created by Álvaro Golbano Durán
//

#include "StackNode.hpp"
#include <iostream>
using namespace std;

//____________Cosntructors_______________

StackNode::StackNode(User stackElem)
{
    this->next = nullptr;
    this->element = stackElem;
}

//____________Acccss Methods_______________

void StackNode::setNext(StackNode *stackNext)
{
    this->next = stackNext;
}

void StackNode::setElement(User stackElem)
{
    this->element = stackElem;
}

StackNode *StackNode::getNext()
{
    return this->next;
}

User StackNode::getElement()
{
    return this->element;
}