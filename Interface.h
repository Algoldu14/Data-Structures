//
// Created by Álvaro Golbano Durán
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "CoreLogic.h"

class Interface
{
private:
    friend class CoreLogic;

public:
    Interface();

    ~Interface();
    
    void startInterface();
};

#endif //INTERFACE_H