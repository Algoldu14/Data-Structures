//
// Created by Álvaro Golbano Durán
//

#include "Interface.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;
//________Constructor and Destructor_________
Interface::Interface() {}

Interface::~Interface() {}

void Interface::startInterface()
{
    CoreLogic coreLogic;
    char option;
    int *aux;
    do
    {
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t                          MMR                              \n";
        cout << "\t---------------------------------------------------------\n";
        cout << "\n\tA. Start simulation.\n";
        cout << "\tB. Search a phone number. \n";
        cout << "\tC. List of 100 phone-ID in the tree.\n";
        cout << "\tD. Efficiency comparison.\n";
        cout << "\tE. 555 printing.\n";
        cout << "\tS. EXIT\n\n";
        cout << "\tIntroduce an option: ";
        cin >> option;
        option = toupper(option);

        switch (option)
        {
        case 'A':
        {
            coreLogic.createQMMR();
            aux = coreLogic.generateUsers();
            cout << "\n\tThe number of users generated are: " << aux[0] << endl;
            cout << "\tThe number of 555 phones are: " << aux[1] << endl;
            break;
        }
        case 'B':
        {

            int phoneNumber, phoneNumberAux, counter;
            cout << "\n\tInsert the phone number you want to see (between 1 and 9 digit): " << endl;
            cin >> phoneNumber;
            string phoneNumberStr = to_string(phoneNumber);
            phoneNumberAux = phoneNumber;
            counter = 0;
            if (phoneNumber > 1 && phoneNumber < 999999999) //If the number is between the correct values
            {
                while (phoneNumberAux < 1000000000 && phoneNumberStr.length() <= 9) //
                {
                    //cout<<"entro aqui---------------------------"<<endl;
                    phoneNumberAux = phoneNumberAux * 10;
                    //cout << "phoneNumberAux: " << phoneNumberAux << endl;
                    counter++; //The number of digits remaining
                    //cout << "counter: " << counter << endl;
                }
                //cout << "phoneNUmber: " << phoneNumber << " | counter: " << counter << endl;
                User user = coreLogic.findPhoneNumber(phoneNumber, counter);
                cout << "\n\tThe first room with the given number or similar is: " << user.getRoom() << " and his phone is: " << user.getPhoneNumber() << endl;
                //cout << "The room of the phone number is: " << coreLogic.findPhoneNUmber(phoneNumber, counter) << endl;
            }
            else
            {
                cout << "Wrong phone number" << endl;
            }
            break;
        }
        case 'C':
        {
            

            break;
        }
        case 'D':
        {
            cout << "\n\tThe ids generated are: \n";
            int *ids = coreLogic.generateRandomIds(aux[0]);
            for (int i = 0; i < 100; i++) //Corregir
            {
                cout << "\tID number: " << i << " number: " << ids[i] << endl;
            }
            coreLogic.stackSearch(ids);
            coreLogic.listSearch(ids);
            coreLogic.treeSearch(ids);
            break;
        }
        case 'E':
        {
			coreLogic.phoneId100(aux[0]);
            break;
        }
        case 'S':
        {
            cout << "\n\tLeaving the program...\n";
            break;
        }

        default:
            cout << "\n\tIncorrect option!\n\n";
            break;
        }

    } while (option != 'S');
}