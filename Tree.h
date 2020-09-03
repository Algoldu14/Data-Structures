//
// Created by Álvaro Golbano Durán
//

#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"

class Tree
{
private:
    TreeNode *root;

public:
    Tree(TreeNode *root);
    Tree(); //Dummy constructor
    ~Tree();

    void postOrder(TreeNode *b);
    TreeNode *getRoot();
    void setRoot(TreeNode *root);
    TreeNode *getSon(TreeNode *b, int a);
    void insert(TreeNode *b, User u);
    bool isEmpty();
    void preOrder(TreeNode *node);
};

#endif // TREE_H
