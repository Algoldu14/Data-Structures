//
// Created by Álvaro Golbano Durán
//

#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "CoreLogic.hpp"

class Interface
{
private:
    friend class CoreLogic;

public:
    Interface();

    ~Interface();
    
    void startInterface();
};

#endif //INTERFACE_HPP