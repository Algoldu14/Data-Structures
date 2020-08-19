//
// Created by Álvaro Golbano Durán
//

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include <iostream>
using namespace std;

class QueueNode
{
private:
    QueueNode *next;
    char queueData;

public:
    //Cosntructor methods
    QueueNode(char queueData);
    ~QueueNode();

    //Access methods
    QueueNode *getNext();
    char getContent();
    void setNext(QueueNode *qNext);
    void setContent(char qCont);
};

#endif //QUEUENODE_HPP