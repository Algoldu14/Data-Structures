//
// Created by Álvaro Golbano Durán
//

#include "Interface.h"
#include <iostream>

using namespace std;
//________Constructor_________

Interface::Interface() {}

Interface::~Interface() {}

void Interface::startInterface()
{
    CoreLogic coreLogic;
    char option;
    do
    {
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t                          MMR                              \n";
        cout << "\t-----------------------------------------------------------\n";
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
            coreLogic.createQMMR();
            cout << "The number of 555 phones are: " << coreLogic.generateUsers() << endl;
            break;
        case 'B':
            int phoneNumber, phoneNumberAux, counter;
            cout << "Insert the phone number you want to see (between 1 and 9 digit): " << endl;
            cin >> phoneNumber;
            phoneNumberAux = phoneNumber;
            counter = 0;
            if (phoneNumber > 1 && phoneNumber < 999999999) //If the number is between the correct values
            {
                while (phoneNumberAux > 10)
                {
                    phoneNumberAux = phoneNumberAux / 10;
                    counter++; //The number of digits
                }
                cout << "The room of the phone number is: " << coreLogic.findPhoneNUmber(phoneNumber, counter) << endl;
            }
            break;

        case 'C':

            break;

        case 'D':

            break;

        case 'S':
            cout << "\n\tLeaving the program...\n";
            break;

        default:
            cout << "\n\tIncorrect option!\n\n";
            break;
        }

    } while (option != 'S');
}