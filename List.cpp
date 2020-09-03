//
// Created by Álvaro Golbano Durán
//

#include "List.h"
#include <iostream>
using namespace std;

//____________Cosntructor and destructor____________

List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
}

List::~List()
{
}

// Inserts the specified value at the specified position.
// If pos is negative, the value will be inserted at the front.
// If pos is bigger than the size, value will be appended to the list.

void List::Insert(User element, int pos)
{
    // Create the new node to insert.
    ListNode *newNode = new ListNode(element);

    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        // Check for position 0 or smaller.
        if (pos <= 0)
        {
            this->AddStart(newNode);
        }
        else
        {
            ListNode *current = this->head;

            int ctr = 0;
            while ((ctr < pos) && (current != nullptr))
            {
                current = current->getNext();
                ctr++;
            }

            // Check if in bounds or out of bounds.
            if (current == nullptr)
            {
                // Append to List.
                this->Append(element);
            }
            else
            {
                // Add in specified position.
                this->Add(newNode, current);
            }
        }
    }
}

// ______________FUNCTIONS TO SIMPLIFY THE ABOVE FUNCTION__________________

// Add the new node at the end of the list.

void List::Append(User newElement)
{    
    ListNode *newNode = new ListNode(newElement);
    this->tail->setNext(newNode);
    newNode->setPrev(this->tail);
    this->tail = newNode;
}

User List::checkInPosList(int position)
{
    ListNode *current = this->head;
    if (this->head != nullptr) // If list is not empty.
    {
        if (position == 0) // If list has only one element
        {
            return current->getElement();
        }
    }
    else
    {
        int counter = 0;
        //Iterate until specified position or out of bounds.
        while ((counter < position) && (current != nullptr))
        {
            current = current->getNext();
            counter++;
        }
    }
    return current->getElement();
}
// Add the new node in the position of the current node specified.

void List::Add(ListNode *newNode, ListNode *current)
{
    newNode->setNext(current->getNext());
    newNode->getNext()->getPrevious()->setNext(newNode);
    newNode->setPrev(current);
    current->setNext(newNode);
}

// Inserts the new node at the beginning of the List.

void List::AddStart(ListNode *newNode)
{
    newNode->setNext(this->head);
    this->head->setPrev(newNode);
    this->head = newNode;
}

// Deleted the element from the specified position.
// This function will do nothing if position is out of bounds or empty list.

void List::Remove(int pos)
{
    if (this->head != nullptr) // If list is not empty.
    {
        if (this->head == this->tail) // If list has only one element.
        {
            if (pos == 0)
            {
                this->EmptyRemove();
            }
        }
        else // If list has more than one element.
        {
            ListNode *current = this->head;

            // No need to iterate. Already have access to head.
            if (pos == 0)
            {
                this->HeadRemove(current);
            }
            else
            {
                int ctr = 0;
                // Iterate until specified position or out of bounds.
                while ((ctr < pos) && (current != nullptr))
                {
                    current = current->getNext();
                    ctr++;
                }

                // Make sure not out of bounds.
                if (current != nullptr)
                {
                    // Special handling if last element.
                    if (current == this->tail)
                    {
                        this->TailRemove(current);
                    }
                    else
                    {
                        this->RegularRemove(current);
                    }
                }
            }
        }
    }
}

//_____________FUNCTIONS TO SIMPLIFY THE ABOVE FUNCTION_____________

// Removes an element and resets the list.
void List::EmptyRemove()
{
    delete (this->head);
    this->head = nullptr;
    this->tail = nullptr;
}

// Removes an element from the head when the list is size > 1.

void List::HeadRemove(ListNode *current)
{
    this->head->getNext()->setPrev(nullptr);
    this->head = this->head->getNext();
    delete (current);
}

// Removes an element from the tail of the list when the list is size > 1.

void List::TailRemove(ListNode *current)
{
    current->getPrevious()->setNext(nullptr);
    this->tail = current->getPrevious();
    delete (current);
}

// Removes an element from a position between 1 and size-2.

void List::RegularRemove(ListNode *current)
{
    current->getPrevious()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrevious());
    delete current;
}

bool List::isEmpty()
{
	return this->head == nullptr;
}

