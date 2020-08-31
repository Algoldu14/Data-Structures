//
// Created by Álvaro Golbano Durán
//

#ifndef LISTNODE_H
#define LISTNODE_H
#include "User.h"

class ListNode
{
private:
    User element;       // Element of the node
    ListNode *previous; // Pointer to the previous node
    ListNode *next;     // Pointer to the next node
	
public:
	ListNode(User u);
	~ListNode();

	//Access methods
    ListNode *getNext();
    ListNode *getPrevious();
    User getElement();

    void setNext(ListNode *listNxt);
    void setPrev(ListNode *listPrev);
    void setElement(User listElem);
};

#endif // LISTNODE_H
