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
    int element;     //The element of the stackNode
public:
    //Constructor and destructor
	StackNode(int stackElem);
	~StackNode();
	
	//Access methods

    void setNext(StackNode *stackNext);
    void setElement(int stackElem);
    StackNode *getNext();
    int getElement();

};

#endif // STACKNODE_H
