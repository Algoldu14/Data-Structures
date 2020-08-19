//
// Created by Álvaro Golbano Durán
//

#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"
#include <iostream>
using namespace std;

class Stack
{
private:
    StackNode *top; //A pointer to the top of the stack
public:
    Stack();
    ~Stack();

    //ADT Methods
    void Push(int stackElem); //Push the element into the stack
    int Pop();                //Removes the top element of the stack
    void makeNull();          //Makes the stack empty
    bool isEmpty();           //Checks if the stack is empty
    StackNode *getTop();      //Get the top of the stack
};

#endif //STACK_HPP
