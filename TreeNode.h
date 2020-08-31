//
// Created by Álvaro Golbano Durán
//

#ifndef TREENODE_HPP
#define TREENODE_HPP
#include "User.hpp"

class TreeNode
{
private:
    User user;
    //Left and Right son:
    TreeNode *Lson;
    TreeNode *Rson;
    friend class Tree;
    friend class CoreLogic;

public:
    TreeNode(User u, TreeNode *Rson, TreeNode *Lson);
    ~TreeNode();
    User getUser();
};
typedef TreeNode* tnode;

#endif //TREENODE_HPP