//
// Created by Álvaro Golbano Durán
//

#include "TreeNode.h"

TreeNode::TreeNode(User u, tnode Rson, tnode Lson)
{
	this->user = u;
    this->Rson = Rson;
    this->Lson = Lson;
}

TreeNode::~TreeNode(){}

User TreeNode::getUser()
{
    return this->user;
}