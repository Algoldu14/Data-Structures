//
// Created by Álvaro Golbano Durán
//

#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"

private:
    tnode root;
class Tree
{
public:
	Tree(tnode root);
	~Tree();
	
	void preOrder(tnode a);
    void postOrder(tnode b);
    tnode getRoot();
    void setRoot(tnode root);
    tnode getSon(tnode b, int a);
    void insert(tnode b, User u);
    bool isEmpty();

};

#endif // TREE_H
