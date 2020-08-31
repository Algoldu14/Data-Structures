//
// Created by Álvaro Golbano Durán
//

#ifndef CORELOGIC_H
#define CORELOGIC_H

#include "Queue.h"
#include "Stack.h"
#include "User.h"
#include "List.h"
#include "Tree.h"

class CoreLogic
{
	private:
    Queue mmrQueue1, mmrQueue2;
    Tree userTree;
    Stack phones555;
    List listPhones;

    friend class Queue;
    friend class Stack;
    friend class User;
    friend class List;
	
public:
	//Cosntructor and destructor
	CoreLogic();
	~CoreLogic();
	
	//Methods
    void createQMMR();
    char MMR(); //The algorithm to assing a new user
    int generateUsers();
    char findPhoneNUmber(int phoneToF, int lenDigi);
    bool theyAreEqual(int phoneN, int phoneU);

};

#endif // CORELOGIC_H
