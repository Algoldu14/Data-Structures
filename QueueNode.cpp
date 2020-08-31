//
// Created by Álvaro Golbano Durán
//

#include "QueueNode.h"
#include <iostream>
using namespace std;

//_________Cosntructor_________

QueueNode::QueueNode(char queueData)
{
    this->queueData = queueData;
    this->next = nullptr;
}

QueueNode::~QueueNode() {}

//________Access Methods________

QueueNode *QueueNode::getNext() //Gets the next element of the queue
{
    return this->next;
}

char QueueNode::getContent()
{
    return this->queueData;
}

void QueueNode::setNext(QueueNode *qNext)
{
    this->next = qNext;
}

void QueueNode::setContent(char qCont)
{
    this->queueData = qCont;
}