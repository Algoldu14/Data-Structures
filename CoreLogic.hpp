//
// Created by Álvaro Golbano Durán
//

#ifndef CORELOGIC_HPP
#define CORELOGIC_HPP

#include "Queue.hpp"
#include "Stack.hpp"
#include "User.hpp"
#include "Tree.hpp"
#include <iostream>
using namespace std;

class CoreLogic
{

private:
    Queue mmrQueue1, mmrQueue2;
    Tree userTree;
    friend class Queue;
    friend class Stack;
    friend class User;
    friend class List;

public:
    //Cosntructor and destructor
    CoreLogic() {}
    ~CoreLogic() {}

    //Methods

    void createQMMR(){}
    char MMR() {} //The algorithm to assing a new user
    int generateUsers(){}
};

#endif //CORELOGIC_HPP