//
// Created by Álvaro Golbano Durán
//

#include "User.h"
#include <iostream>
using namespace std;

User::User() {} //Dummy constructor
User::User(int id, int phoneN, char room)
{
    this->id = id;
    this->phoneNumber = phoneN;
    this->room = room;
}

User::~User() {} //Destructor

//____________Getters and Setters__________

void User::setID(int id)
{
    this->id = id;
}

void User::setPhoneNumber(int phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void User::setRoom(char room)
{
    this->room = room;
}

int User::getID()
{
    return this->id;
}

int User::getPhoneNumber()
{
    return this->phoneNumber;
}

char User::getRoom()
{
    return this->room;
}
void User::showData()
{
    cout << "User id: " << this->getID() << endl;
    cout << "User phone number: " << this->getPhoneNumber() << endl;
    cout << "User room: " << this->getRoom() << endl;
}