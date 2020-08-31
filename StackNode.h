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
    int element;     //The element of the stackNode
    friend class Stack;
public:
    //Constructors

    StackNode(int stackElem);
    ~StackNode();

    //Access methods

    void setNext(StackNode *stackNext);
    void setElement(int stackElem);

    StackNode *getNext();
    int getElement();
};

#endif //STACKNODE_HPP