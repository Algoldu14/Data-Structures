//
// Created by Álvaro Golbano Durán
//

#include "Stack.hpp"
#include <iostream>
using namespace std;

//____________Cosntructor_______________

Stack::Stack()
{
    this -> top = nullptr;
}

Stack::~Stack(){} //Destructor

//___________Access Methods____________

StackNode* Stack::getTop()
{
    return this -> top;
}