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
#include <array>
using namespace std;

//___________Costructor and Destructor_____________
CoreLogic::CoreLogic() {}

CoreLogic::~CoreLogic() {}

//___________Methods______________
char CoreLogic::MMR()
{
    int counterQ1 = 26;
    int counterQ2 = 26;
    int r = rand() % 11; //Generates a random number between 1 and 10
    int r2 = rand() % 11;
    char aux;
    if (r < 6) //The 60%
    {
        aux = this->mmrQueue2.Dequeue(); //Dequeues from the second queue
        counterQ2--;
        if (r2 < 7 || counterQ2 > 13) //The 70% and the queue is big enough
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
        if (r2 < 7 || counterQ1 > 13) //The 70%
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

    //First user
    this->allPhones.Push(newU);
    this->listPhones.Insert(newU, 0);
    this->userTree.setRoot(aux);
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
        //newU.showData();

        this->userTree.insert(this->userTree.getRoot(), newU); //Insert the node in the TREE
        this->allPhones.Push(newU);                            //Push for the exercise 4 STACK
        this->listPhones.Insert(newU, i);                      //Insert for the exercise 4 LIST
        int first3 = (int)(phoneN / 1000000);                  //Take the first 3 digits of the phone number
        //cout << "First three digits: " << first3 << endl;
        if (first3 == 555)
        {
            this->phones555.Push(newU);
            phone555Counter++;
            //cout << "555 cont: " << phone555Counter << endl;
            cout << "\tPhone555: " << phoneN << endl;
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
        //cout << "phoneToF: " << phoneToF <<"aux->getUser().getPhoneNumber(): "<<aux->getUser().getPhoneNumber()<<endl;
        if (this->theyAreEqual(phoneToF, aux->getUser().getPhoneNumber())) //If they are equal
        {
            //cout << "The phone that matches first is: " << aux->getUser().getPhoneNumber() << endl;
            //cout << "Finded: " << aux->getUser().getPhoneNumber() << " = " << phoneToF << endl;
            return aux->getUser(); //We return the room where the match is maked
        }
        else
        {
            //cout << "phoneToF before for ----------------: " << phoneToF << endl;
            for (int i = 0; i < lenDigi; i++)
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

                    for (int i = 0; i < lenDigi; i++)
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

                    for (int i = 0; i < lenDigi; i++)
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
    return aux->getUser();
}

bool CoreLogic::theyAreEqual(int phoneToF, int phoneU) //Checks if two given numbers are equal || phoneU >= phoneToF (always)
{
    bool coincidence = true;
    string phoneToFStr = to_string(phoneToF);
    string phoneUStr = to_string(phoneU);
    int lenPhoneToF = phoneToFStr.length();
    if (phoneToF == phoneU)
    {
        coincidence = true;
        return coincidence;
    }

    for (int i = 0; i < lenPhoneToF; i++)
    {
		//cout << "phoneToFS[i] --------------- " << phoneToFStr[i] << endl;
        //cout << "phoneUS[i]   --------------- " << phoneUStr[i] << endl;
        if (phoneToFStr[i] != phoneUStr[i])
        {
            coincidence = false;
            break;
        }
    }
    return coincidence;
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
    for (int i = 0; i < 100; i++)
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
    cout << "\n\t++++++++++++++ Start the search in the stack ++++++++++++++\n"
         << endl;
    auto start = chrono::steady_clock::now();
    User user;
    int matchCounter = 0;
    while (matchCounter < 100 || this->allPhones.getTop() != nullptr)
    {
        user = this->allPhones.Pop();
        if (this->isInTheArray(user.getID(), randomIds)) //If we find all the id
        {
            matchCounter++;
            cout << "\tUser(id): " << user.getID() << endl;
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in a stack: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " miliseconds" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}

void CoreLogic::listSearch(int *randomIds)
{
    cout << "\n\t++++++++++++++ Start the search in the list ++++++++++++++\n"
         << endl;
    auto start = chrono::steady_clock::now();
    User user;
    int matchCounter = 0;
    int posList = 0;
    while (matchCounter < 100)
    {
        user = this->listPhones.checkInPosList(posList);
        if (this->isInTheArray(user.getID(), randomIds)) //If we find the id in this position
        {
            matchCounter++;
            cout << "\tUser(id): " << user.getID() << endl;
        }
        posList++;
    }
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in the list: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " miliseconds" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}

void CoreLogic::treeSearch(int *randomIds)
{
    cout << "\n\t++++++++++++++ Start the search in the tree ++++++++++++++" << endl;
    auto start = chrono::steady_clock::now();
    TreeNode *aux = this->userTree.getRoot();
    this->preOrderSearch(randomIds, aux);
    auto end = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the ids in the tree: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " miliseconds" << endl;
    cout << "\n\t-----------------------------------------------------------------------------" << endl;
}

void CoreLogic::preOrderSearch(int *randomIds, TreeNode *node)
{
    if (node != nullptr)
    {
        if (this->isInTheArray(node->getUser().getID(), randomIds))
        {
            cout << "\tUser(id): " << node->getUser().getID() << endl;
        }
        this->preOrderSearch(randomIds, node->getLson());
        this->preOrderSearch(randomIds, node->getRson());
    }
}

void CoreLogic::phoneId100(int maxId)
{
    int id = rand() % maxId + 1;
    cout << "\n\tThe id selected is: " << id << endl;
    TreeNode *idNode = nullptr;
	idNode = this->preOrderSearchId(id, this->userTree.getRoot());
    idNode->getUser().showData();
    cout << "\tThe tree in preorder criteria is: " << endl;
    this->preorderPrint(idNode, 0);
}

TreeNode *CoreLogic::preOrderSearchId(int id, TreeNode *node)
{
    if (node != nullptr)
    {
        if (node->getUser().getID() == id)
        {
            node->getUser().showData();
            return node;
        }
        preOrderSearchId(id, node->getLson());
        preOrderSearchId(id, node->getRson());
    }
}

void CoreLogic::preorderPrint(TreeNode *node, int counter)
{
    if (counter < 100 || node != nullptr)
    {
        node->getUser().showData();
        cout << "--------------------" << endl;
        counter++; //Puede que se haya que mover
        this->preorderPrint(node->getLson(), counter);
        //aqui otro
        this->preorderPrint(node->getRson(), counter);
    }
}

void CoreLogic::printing555()
{
    Stack auxStack = this->phones555;
    TreeNode *auxTree = this->userTree.getRoot();

    auto start1 = chrono::steady_clock::now();
    while (!auxStack.isEmpty())
    {
        User u = auxStack.Pop();
        cout << "\tUser(id): " << u.getID() << endl;
    }
    auto end1 = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to print the stack numbers is: " << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count() << " miliseconds" << endl;
    cout << "\n\t-----------------------------------------------------------------------------\n" << endl;

    auto start2 = chrono::steady_clock::now();
    this->preOrderSearch555(auxTree);
    auto end2 = chrono::steady_clock::now();
    cout << "\n\tThe elapsed time to find the 555 numbers in the tree is: " << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count() << " miliseconds" << endl;
    cout << "\n\t-----------------------------------------------------------------------------\n" << endl;
}

void CoreLogic::preOrderSearch555(TreeNode *node)
{
    if (node != nullptr)
    {
        if (theyAreEqual(555, node->getUser().getPhoneNumber()))
        {
            cout << "\tUser(id): " << node->getUser().getID() << endl;
        }
        this->preOrderSearch555(node->getLson());
        this->preOrderSearch555(node->getRson());
    }
}