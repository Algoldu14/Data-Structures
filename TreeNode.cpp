//
// Created by Álvaro Golbano Durán
//

#include "TreeNode.h"

TreeNode::TreeNode(User u, TreeNode* Rson, TreeNode* Lson)
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

TreeNode* TreeNode::getLson()
{
	return this->Lson;
}

TreeNode* TreeNode::getRson()
{
	return this->Rson;
}

void TreeNode::setLson(TreeNode* lson)
{
	this->Lson = lson;
}

void TreeNode::setRson(TreeNode* rson)
{
	this->Rson = rson;
}