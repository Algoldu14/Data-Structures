//
// Created by Álvaro Golbano Durán
//

#include "Queue.hpp"
#include "Stack.hpp"
#include "User.hpp"
#include "List.hpp"
#include "CoreLogic.hpp"
#include <iostream>
using namespace std;

//___________Costructor______________

CoreLogic::CoreLogic() {}
CoreLogic::~CoreLogic() {}

//___________Methods______________
char CoreLogic::MMR()
{
    int r = rand() % 11; //Generates a random number between 1 and 10
    int r2 = rand() % 11;
    //int cont1, cont2 = 0;
    char aux = NULL;
    if (r < 6) //The 60%
    {
        aux = this->mmrQueue2.Dequeue(); //Dequeues from the second queue

        if (r2 < 7) //The 70% and the queue is big enough
        {
            this->mmrQueue2.Enqueue(aux);
        }
        else
        {
            this->mmrQueue1.Enqueue(aux);
        }
    }
    else //The 40%
    {
        aux = this->mmrQueue1.Dequeue(); //Dequeues from the first queue

        if (r2 < 7) //The 70%
        {
            this->mmrQueue1.Enqueue(aux);
        }
        else
        {
            this->mmrQueue2.Enqueue(aux);
        }
    }

    return aux;
}

void CoreLogic::createQMMR()
{
    char AtoZ[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};

    char ZtoA[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q',
                     'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G',
                     'F', 'E', 'D', 'C', 'B', 'A'};

    for (int i = 0; i < 26; i++) //Enqueues the two queues needed for the algorithm
    {
        this->mmrQueue1.Enqueue(AtoZ[i]);
        cout << "Primera letra de la Q1:", AtoZ[i], "\n";
        this->mmrQueue2.Enqueue(ZtoA[i]);
        cout << "Primera letra de la Q2:", ZtoA[i], "\n";
    }
}

int CoreLogic::generateUsers()
{
    int phoneN = rand() % ((999999999 - 100000000) + 1); //Random Number between 100000000 and 999999999
    User newU;
    newU.setID(0); //First ID
    newU.setPhoneNumber(phoneN);
    newU.setRoom(MMR());
    tnode aux = new TreeNode(newU, nullptr, nullptr);
    this->userTree.setRoot(aux); //First user

    for (int i = 1; i < rand() % ((50000 - 10000) + 1); i++) //Generates the rest of the users
    {
        int phoneN = rand() % ((999999999 - 100000000) + 1); //Random Number between 100000000 and 999999999
        User newU;
        newU.setID(i);
        newU.setPhoneNumber(phoneN);
        newU.setRoom(MMR());
        this->userTree.insert(this->userTree.getRoot(), newU);
    }
    return 0; //Not yet implemented, returns the number of phone numbers that starts with 555
}