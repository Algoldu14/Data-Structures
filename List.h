//
// Created by Álvaro Golbano Durán
//

#ifndef LIST_H
#define LIST_H
#include "ListNode.h"
#include "User.h"

class List
{
private:
    ListNode *head;
    ListNode *tail;

public:
    List();
    ~List();

    void Insert(User element, int pos); //Inserts a element on the list in a given position
    void Remove(int pos);               //Removes a element of the list from a given position
    int Locate(User value);             //Locates the place of a element in the list
    User checkInPosList(int position);  //Retrieves the user in the given position without deleting it
    void MakeNull();                    //Makes the list empty
    bool isEmpty();                     //Checks if the list is empty

    // Auxiliary functions to Insert Function.
    void Append(User newElement);
    void Add(ListNode *newnode, ListNode *current);
    void AddStart(ListNode *newNode);

    // Auxiliary functions to the Remove Function.
    void EmptyRemove();
    void RegularRemove(ListNode *current);
    void HeadRemove(ListNode *current);
    void TailRemove(ListNode *current);
};

#endif // LIST_H
