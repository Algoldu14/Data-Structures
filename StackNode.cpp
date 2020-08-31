//
// Created by Álvaro Golbano Durán
//

#include "StackNode.h"

//____________Cosntructor and destructor_______________

StackNode::StackNode(int stackElem)
{
    this->element = stackElem;
	this->next = nullptr;
}

StackNode::~StackNode(){}

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