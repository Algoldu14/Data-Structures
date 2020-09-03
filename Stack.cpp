//
// Created by Álvaro Golbano Durán
//

#include "Stack.h"

//____________Cosntructor and Destructor_______________
Stack::Stack()
{
    this->top = nullptr;
}

Stack::~Stack() {}

//___________Access Methods____________

StackNode *Stack::getTop()
{
    return this->top;
}

//____________ADT Methods_______________

void Stack::Push(User stackElem) // Puts the introduced element at the top of the stack.
{
    //Create the new element to be added
    StackNode *newElem = new StackNode(stackElem);

    //Checks if the stack is empty
    if (this->top == nullptr)
    {
        this->top = newElem;
    }
    else
    {
        newElem->setNext(this->top); //New element will point to the current top
        this->top = newElem;         //and the new top wi point to the newElem
    }
}

User Stack::Pop() //Removes the top element from the stack and return it. If the stack is empty, retunr null
{
    StackNode *removed = this->top;
    User result;

    if (this->top != nullptr)
    {
        result = removed->getElement();
        this->top = removed->getNext();
        delete removed;
    }
    return result;
}

void Stack::makeNull() //Makes the stack empty by making pop intil is empty
{
    while (this->top != nullptr)
    {
        Pop();
    }
}

bool Stack::isEmpty() //Checks if the stack is empty
{
    return this->top == nullptr;
}