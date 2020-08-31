//
// Created by Álvaro Golbano Durán
//

#include "StackNode.h"
#include <iostream>
using namespace std;

//____________Cosntructors_______________

StackNode::StackNode(int stackElem)
{
    this->next = nullptr;
    this->element = stackElem;
}

//____________Acccss Methods_______________

void StackNode::setNext(StackNode *stackNext)
{
    this->next = stackNext;
}

void StackNode::setElement(int stackElem)
{
    this->element = stackElem;
}

StackNode *StackNode::getNext()
{
    return this->next;
}

int StackNode::getElement()
{
    return this->element;
}