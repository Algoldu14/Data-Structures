//
// Created by Álvaro Golbano Durán
//

//__________Constructor_________

#include "Tree.hpp"

Tree::Tree(tnode root)
{
    this->root = root;
}
Tree::~Tree() {}

bool Tree::isEmpty()
{
    return this->root == nullptr;
}

