//
// Created by Álvaro Golbano Durán
//

#include "Queue.h"
#include <cstddef>
//___________Constructors____________

Queue::Queue()
{
    this->front = nullptr;
    this->rear = nullptr;
}

Queue::~Queue() {}

//___________ADT Methods____________

void Queue::Enqueue(char elem) //Inserts a new element in the queue, at the rear
{
    QueueNode *newElem = new QueueNode(elem);

    if (this->isEmpty())
    {
        this->front = newElem;
        this->rear = newElem;
    }
    else
    {
        this->rear->setNext(newElem);
        this->rear = newElem;
    }
}

char Queue::Dequeue() // Removes the element at the front of the queue and returns it. This method will return null if the queue is empty.
{
    QueueNode *removed = this->front;
    char obtained = NULL;

    if (this->front != NULL)
    {
        obtained = removed->getContent();
        this->front = removed->getNext();
        delete removed;
    }
    return obtained;
}

void Queue::makeNull() //Dequeues the queue until the front is a nullptr
{
    while (this->front != nullptr)
    {
        Dequeue();
    }
}

bool Queue::isEmpty() //Checks if the queue is empty
{
    return this->front == nullptr;
}