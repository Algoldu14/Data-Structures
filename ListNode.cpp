//
// Created by Álvaro Golbano Durán
//
#include "ListNode.hpp"

//_____________Cosntructor______________

ListNode::ListNode(User element)
{
    this->element = element;
    this->previous = nullptr;
    this->next = nullptr;
}

ListNode::~ListNode() {}

//_____________Access Methods____________

ListNode *ListNode::getNext()
{
    return this->next;
}

ListNode* ListNode::getPrevious()
{
    return this -> previous;
}

User ListNode::getElement()
{
    return this->element;
}

void ListNode::setNext(ListNode *listNxt)
{
    this -> next = listNxt;
}

void ListNode::setPrev(ListNode *listPrev)
{
    this -> previous = listPrev;
}

void ListNode::setElement(User listElem)
{
    this -> element = listElem;
}