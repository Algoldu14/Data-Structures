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
    void startInterface();

    Interface();

    ~Interface();
};

#endif //INTERFACE_HPP