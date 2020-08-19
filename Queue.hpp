//
// Created by Álvaro Golbano Durán
//

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"
#include <iostream>
using namespace std;

class Queue
{
private:
    QueueNode *front; //A pointer to the front of the queue
    QueueNode *rear;  //A pointer to the rear of the queue

public:
    //Cosntructor and destructor
    Queue();
    ~Queue();

    //ADT methods for Queues
    void Enqueue(char elem); //Inserts the new element at the end of the queue
    char Dequeue();          //Removes the first element of the queue
    char Front();            //Returns the first element of the queue
    void makeNull();         //Empties the queue
    bool isEmpty();          //Chacks if the queue is empty
};

#endif //QUEUE_HPP