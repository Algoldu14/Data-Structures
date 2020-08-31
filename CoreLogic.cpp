//
// Created by Álvaro Golbano Durán
//

#include "CoreLogic.h"
#include "Queue.h"
#include "Stack.h"
#include "User.h"
#include "List.h"
#include <iostream>
using namespace std;

//___________Costructor and Destructor_____________
CoreLogic::CoreLogic(){}

CoreLogic::~CoreLogic(){}

//___________Methods______________
char CoreLogic::MMR()
{
    int r = rand() % 11; //Generates a random number between 1 and 10
    int r2 = rand() % 11;
    char aux;
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
        this->mmrQueue2.Enqueue(ZtoA[i]);
    }
}

int* CoreLogic::generateUsers()
{
    int phone55Counter, userCounter = 0;
	int* retunArr = new int[2];
    //We generate the fisrst user to be the root of the tree
    int phoneN = rand() % 899999999 + 100000000 ; //Random Number between 100000000 and 999999999
    User newU;
    newU.setID(0); //First ID
    newU.setPhoneNumber(phoneN);
    newU.setRoom(this->MMR());
    TreeNode* aux = new TreeNode(newU, nullptr, nullptr);
    this->userTree.setRoot(aux); //First user

    for (int i = 1; i < rand() % 50000 + 10000; i++) //Generates the rest of the users
    {
        int phoneN = rand() % 899999999 + 100000000;
        User newU;
        newU.setID(i);
        newU.setPhoneNumber(phoneN);
        newU.setRoom(this->MMR());
        this->userTree.insert(this->userTree.getRoot(), newU); //Insert the node in the tree
        int first3 = (int)(phoneN / 1000000);                  //Take the first 3 digits of the phone number
        if (first3 == 555)
        {
            this->phones555.Push(phoneN);
            phone55Counter++;
        }
		userCounter = i;
    }
    retunArr[0] = userCounter;
	retunArr[1] = phone55Counter;
    return retunArr;
}

char CoreLogic::findPhoneNUmber(int phoneToF, int lenDigi) //Finds the first number that matches with phone
{
    bool finding = true;
    TreeNode* aux = nullptr;
    aux = this->userTree.getRoot();
    while (finding)
    {
        if (this->theyAreEqual(phoneToF, aux->getUser().getPhoneNumber())) //If they are equal
        {
            cout << "The phone that matches first is: " << aux->getUser().getPhoneNumber() << endl;
            return aux->getUser().getRoom(); //We return the room where the match is maked
        }
        else
        {
            for (int i = 0; i < 9 - lenDigi; i++)
            {
                phoneToF = phoneToF * 10; //Create the complete phone number
            }
            if (aux->getUser().getPhoneNumber() - phoneToF > 0)
            {
                if (this->userTree.getSon(aux, 0) != nullptr)
                {
                    aux = this->userTree.getSon(aux, 0); //We get the Lson

                    for (int i = 0; i < 9 - lenDigi; i++)
                    {
                        phoneToF = phoneToF / 10; //Reset the phone number
                    }
                }
                else
                {
                    finding = false;
                }
            }
            else
            {
                if (this->userTree.getSon(aux, 1) != nullptr)
                {
                    aux = this->userTree.getSon(aux, 1); //We get the Rson

                    for (int i = 0; i < 9 - lenDigi; i++)
                    {
                        phoneToF = phoneToF / 10; //Reset the phone number
                    }
                }
                else
                {
                    finding = false;
                }
            }
        }
    }
    cout << "The phone that matches first with" << phoneToF << "is: NONE" << endl;
    return 'Null';
}

bool CoreLogic::theyAreEqual(int phoneN, int phoneU) //Checks if two given numbers are equal || phoneU >= phoneN (always)
{
    int digitN, digitU;
    if (phoneN == phoneU)
    {
        return true;
    }
    else
    {
        while (phoneN > 10)
        {
            digitN = phoneN % 10;
            digitU = phoneU % 10;

            if (digitN != digitU)
            {
                return false;
            }
            else
            {
                phoneN = phoneN / 10;
                phoneU = phoneU / 10;
            }
        }
        return true;
    }
}