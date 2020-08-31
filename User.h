//
// Created by Álvaro Golbano Durán
//

#ifndef USER_H
#define USER_H

class User
{
private:
    int id, phoneNumber;
    char room;
public:
	User(int id, int phoneN, char room);
	~User();
	void setID(int id);
    int getID();
    void setPhoneNumber(int phoneNumber);
    int getPhoneNumber();
    void setRoom(char room);
    char getRoom();

};

#endif // USER_H
