//
// Created by Álvaro Golbano Durán
//

#ifndef CORELOGIC_H
#define CORELOGIC_H

#include "Queue.h"
#include "Stack.h"
#include "User.h"
#include "List.h"
#include "Tree.h"

class CoreLogic
{
private:
    Queue mmrQueue1, mmrQueue2;
    Tree userTree;
    Stack phones555, allPhones;
    List listPhones;


public:
    //Cosntructor and destructor
    CoreLogic();
    ~CoreLogic();

    //Methods
    void createQMMR();
    char MMR();          
    int *generateUsers(); 
    User findPhoneNumber(int phoneToF, int lenDigi);
    bool theyAreEqual(int phoneN, int phoneU);
    int *generateRandomIds(int range);
    bool isInTheArray(int id, int *randomIds);
    void stackSearch(int *randomIds);
    void listSearch(int *randomIds);
    void treeSearch(int *randomIds);
    void preOrderSearch(int *randomIds, TreeNode *node);
    void phoneId100(int maxId);
    void preOrderSearchId(int id, TreeNode *node);
    void preorderPrint(TreeNode* node, int counter);
    void printing555();
    void preOrderSearch555(TreeNode* node);
};

#endif // CORELOGIC_H
