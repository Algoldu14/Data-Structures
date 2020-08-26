//
// Created by Álvaro Golbano Durán
//

//__________Constructor_________

#include "Tree.hpp"

Tree::Tree(tnode root)
{
    this->root = root;
}
Tree::Tree(){} //Dummy constructor
Tree::~Tree() {}

bool Tree::isEmpty()
{
    return this->root == nullptr;
}

tnode Tree::getRoot()
{
    return this->root;
}

void Tree::setRoot(tnode root)
{
    this->root = root;
}

tnode Tree::getSon(tnode b, int a) //If 0 is inserted, it returns the left son
{
    if (a == 0)
    {
        return b->Lson;
    }
    else
    {
        return b->Rson;
    }
}

void Tree::insert(tnode r, User user)
{
    if (r->user.getPhoneNumber().compare(user.getPhoneNumber()) > 0)
    {
        if (r->Lson == nullptr)
        {
            tnode aux = new TreeNode(user, nullptr, nullptr);
            r->Lson = aux;
        }
        else
        {
            insert(r->Lson, user);
        }
    }
    else
    {
        if (r->Rson == nullptr)
        {
            tnode aux = new TreeNode(user, nullptr, nullptr);
            r->Rson = aux;
        }
        else
        {
            insert(r->Rson, user);
        }
    }
}
