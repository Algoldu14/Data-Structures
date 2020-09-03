//
// Created by Álvaro Golbano Durán
//

#include "Tree.h"

//__________Constructor_________

Tree::Tree() {} //Dummy one
Tree::Tree(TreeNode *root)
{
    this->root = root;
}

Tree::~Tree() {}

bool Tree::isEmpty()
{
    return this->root == nullptr;
}

TreeNode *Tree::getRoot()
{
    return this->root;
}

void Tree::setRoot(TreeNode *root)
{
    this->root = root;
}

TreeNode *Tree::getSon(TreeNode *b, int a) //If 0 is inserted, it returns the left son
{
    if (a == 0)
    {
        return b->getLson();
    }
    else
    {
        return b->getRson();
    }
}

void Tree::insert(TreeNode *root, User user)
{
    if (root->getUser().getPhoneNumber() - user.getPhoneNumber() > 0)
    {
        if (root->getLson() == nullptr)
        {
            TreeNode *aux = new TreeNode(user, nullptr, nullptr);
            root->setLson(aux);
        }
        else
        {
            insert(root->getLson(), user);
        }
    }
    else
    {
        if (root->getRson() == nullptr)
        {
            TreeNode *aux = new TreeNode(user, nullptr, nullptr);
            root->setRson(aux);
        }
        else
        {
            insert(root->getRson(), user);
        }
    }
}

void Tree::preOrder(TreeNode *node)
{
    if (node != nullptr)
    {
        node->getUser().showData();
        preOrder(node->getLson());
        preOrder(node->getRson());
    }
}