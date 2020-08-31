//
// Created by Álvaro Golbano Durán
//

#ifndef USER_HPP
#define USER_HPP

class User
{
private:
    int id, phoneNumber;
    char room;

public:
    User(int id, int phoneN, char room) {}
	User(){}
    ~User() {}
    void setID(int id);
    int getID();
    void setPhoneNumber(int phoneNumber);
    int getPhoneNumber();
    void setRoom(char room);
    char getRoom();
};

#endif //USER_HPP