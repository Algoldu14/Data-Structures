//
// Created by Álvaro Golbano Durán
//

#ifndef QUEUENODE_H
#define QUEUENODE_H

class QueueNode
{
private:
    QueueNode *next;
    char queueData;
    friend class Queue;

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

#endif // QUEUENODE_H
