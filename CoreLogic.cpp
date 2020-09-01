//
// Created by Álvaro Golbano Durán
//

#include "CoreLogic.h"
#include "Queue.h"
#include "Stack.h"
#include "User.h"
#include "List.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

//___________Costructor and Destructor_____________
CoreLogic::CoreLogic() {}

CoreLogic::~CoreLogic() {}

//___________Methods______________
char CoreLogic::MMR()
{
    int counterQ1, counterQ2 = 26;
    int r = rand() % 11; //Generates a random number between 1 and 10
    int r2 = rand() % 11;
    char aux;
    if (r < 6) //The 60%
    {
        aux = this->mmrQueue2.Dequeue(); //Dequeues from the second queue
        counterQ2--;
        if (r2 < 7 || counterQ2 < 13) //The 70% and the queue is big enough
        {
            this->mmrQueue2.Enqueue(aux);
            counterQ2++;
        }
        else
        {
            this->mmrQueue1.Enqueue(aux);
            counterQ1++;
        }
    }
    else //The 40%
    {
        aux = this->mmrQueue1.Dequeue(); //Dequeues from the first queue
        counterQ1--;
        if (r2 < 7 || counterQ1 < 13) //The 70%
        {
            this->mmrQueue1.Enqueue(aux);
            counterQ1++;
        }
        else
        {
            this->mmrQueue2.Enqueue(aux);
            counterQ2++;
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

int *CoreLogic::generateUsers()
{
    int phone555Counter = 0;
    int userCounter = 0;
    int *retunArr = new int[2];
    //We generate the fisrst user to be the root of the tree
    int phoneN = rand() % 899999999 + 100000000; //Random Number between 100000000 and 999999999
    User newU;
    newU.setID(0); //First ID
    newU.setPhoneNumber(phoneN);
    newU.setRoom(this->MMR());
    TreeNode *aux = new TreeNode(newU, nullptr, nullptr);
    this->userTree.setRoot(aux); //First user
    userCounter++;
    for (int i = 1; i < rand() % 50000 + 10000; i++) //Generates the rest of the users
    {
        phoneN = 0;
        int digit = 1;
        for (int i = 0; i < 9; i++)
        {
            int phoneD = rand() % 9 + 1;
            //cout << "Digit:" << phoneD << endl;
            phoneN += phoneD * digit;
            //cout << "Phone building: " << phoneN << endl;
            digit *= 10;
        }
        //cout << "---------------------------" << endl;
        digit = 1;
        newU.setID(i);
        newU.setPhoneNumber(phoneN);
        newU.setRoom(this->MMR());
        this->userTree.insert(this->userTree.getRoot(), newU);  //Insert the node in the tree
        this->allPhones.Push(newU);                             //Push for the exercise 4
        this->listPhones.Append(newU);                          //Append for the exercise 4
        int first3 = (int)(phoneN / 1000000);                   //Take the first 3 digits of the phone number
        //cout << "First three digits: " << first3 << endl;
        if (first3 == 555)
        {
            this->phones555.Push(newU);
            phone555Counter++;
            //cout << "555 cont: " << phone555Counter << endl;
            cout << "\tPhone: " << phoneN << endl;
        }
        userCounter++;
    }

    retunArr[0] = userCounter;
    //cout << "User created: " << retunArr[0] << endl;
    retunArr[1] = phone555Counter;
    //cout << "555 cont: " << retunArr[1] << endl;
    return retunArr;
}

User CoreLogic::findPhoneNumber(int phoneToF, int lenDigi) //Finds the first number that matches with phone
{
    bool finding = true;
    TreeNode *aux = nullptr;
    aux = this->userTree.getRoot();
    //cout << "phoneToF before While: " << phoneToF << endl;
    while (finding)
    {
        //cout << "phoneToF While: " << phoneToF << endl;
        if (this->theyAreEqual(phoneToF, aux->getUser().getPhoneNumber())) //If they are equal
        {
            //cout << "The phone that matches first is: " << aux->getUser().getPhoneNumber() << endl;
            //cout << "Finded: " << aux->getUser().getPhoneNumber() << " = " << phoneToF << endl;
            return aux->getUser(); //We return the room where the match is maked
        }
        else
        {
            //cout << "phoneToF before for ----------------: " << phoneToF << endl;
            for (int i = 0; i < lenDigi - 1; i++)
            {
                phoneToF = phoneToF * 10; //Create the complete phone number
                //cout << "phoneToF meanwhile for ----------------: " << phoneToF << endl;
            }
            //cout << "phoneToF after the for: " << phoneToF << endl;
            if (aux->getUser().getPhoneNumber() - phoneToF > 0)
            {
                //cout << "aux->getUser().getPhoneNumber() - phoneToF > 0: " << endl;
                if (this->userTree.getSon(aux, 0) != nullptr)
                {
                    aux = this->userTree.getSon(aux, 0); //We get the Lson

                    for (int i = 0; i < 9 - lenDigi; i++)
                    {
                        phoneToF = phoneToF / 10; //Reset the phone number
                    }
                    //cout << "phoneToF Reseted Lson: " << phoneToF << endl;
                }
                else
                {
                    finding = false;
                }
            }
            else
            {
                //cout << "aux->getUser().getPhoneNumber() - phoneToF < 0: " << endl;
                if (this->userTree.getSon(aux, 1) != nullptr)
                {
                    aux = this->userTree.getSon(aux, 1); //We get the Rson

                    for (int i = 0; i < 9 - lenDigi; i++)
                    {
                        phoneToF = phoneToF / 10; //Reset the phone number
                    }
                    //cout << "phoneToF Reseted Rson: " << phoneToF << endl;
                }
                else
                {
                    finding = false;
                }
            }
        }
    }
    //cout << "The phone that matches first with" << phoneToF << "is: NONE" << endl;
    return aux->getUser();
}

bool CoreLogic::theyAreEqual(int phoneToF, int phoneU) //Checks if two given numbers are equal || phoneU >= phoneToF (always)
{
    string phoneToFS = to_string(phoneToF);
    string phoneUS = to_string(phoneU);

    bool coincidence = true;
    //int lenPhoneToF = phoneToFS.length();

    for (int i = 0; i < 9 - phoneToFS.length(); i++) //Add the needed cer
    {
        //cout << "phoneToFS[i] --------------- " << phoneToFS[i] << endl;
        //cout << "phoneUS[i]   --------------- " << phoneUS[i] << endl;
        if (phoneToFS[i] != phoneUS[i])
        {
            coincidence = false;
            break;
        }
    }
    return coincidence;
}

void CoreLogic::phoneId100()
{
}

int *CoreLogic::generateRandomIds(int range) //Generates the random ids for the shearch
{
    int *retunArr = new int[100];
    for (int i = 0; i < 100; i++)
    {
        int id = rand() % range + 1;
        retunArr[i] = id;
    }
    return retunArr;
}

bool CoreLogic::isInTheArray(int id, int *randomIds)
{
    for (int i = 0; i < sizeof(randomIds); i++)
    {
        if (id == randomIds[i])
        {
            return true;
        }
    }
    return false;
}

void CoreLogic::stackSearch(int *randomIds)
{
    cout << "\n\t++++++++++++++ Start the search in the stack ++++++++++++++" << endl;
    auto start = chrono::steady_clock::now();
    User user;
    int matchCounter = 0;
    while (matchCounter < 100 || this->allPhones.getTop() != nullptr)
    {
        user = this->allPhones.Pop();
        if (this->isInTheArray(user.getID(), randomIds)) //If we didnt find all the ids
        {
            matchCounter++;
            cout << "\tUser (id): " << user.getID() << endl;
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in a stack: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " sec" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}

void CoreLogic::listSearch(int *randomIds)
{
    cout << "\n\t++++++++++++++ Start the search in the list ++++++++++++++" << endl;
    auto start = chrono::steady_clock::now();
    User user;
    int matchCounter, posList = 0;
    while (matchCounter < 100 || !this->listPhones.isEmpty())
    {
        user = this->listPhones.checkInPosList(posList);
        if (this->isInTheArray(user.getID(), randomIds)) //If we didnt find all the ids
        {
            matchCounter++;
            cout << "\tUser (id): " << user.getID() << endl;
        }
        posList++;
    }
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in the list: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " sec" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}

void CoreLogic::treeSearch(int *randomIds)
{
    cout << "\n\t++++++++++++++ Start the search in the list ++++++++++++++" << endl;
    auto start = chrono::steady_clock::now();
    TreeNode *aux = this->userTree.getRoot();
    int matchCounter, posList = 0;
    while (matchCounter < 100 || aux->getLson() != nullptr || aux->getRson() != nullptr)
    {
                  
    }
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in the list: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " sec" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}