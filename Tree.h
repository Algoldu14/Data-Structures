//
// Created by Álvaro Golbano Durán
//

#ifndef TREE_HPP
#define TREE_HPP
#include "TreeNode.hpp"

class Tree
{
private:
    tnode root;

public:
    Tree(tnode root);
    Tree();
    ~Tree();
    void preOrder(tnode a);
    void postOrder(tnode b);
    tnode getRoot();
    void setRoot(tnode root);
    tnode getSon(tnode b, int a);
    void insert(tnode b, User u);
    bool isEmpty();
};

#endif //TREE_HPP