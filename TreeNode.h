//
// Created by Álvaro Golbano Durán
//

#ifndef TREENODE_H
#define TREENODE_H
#include "User.h"

class TreeNode
{
private:
	User user; 
	//Left and Right son:
	TreeNode *Lson;
	TreeNode *Rson;

public:
	TreeNode(User u, TreeNode *Lson, TreeNode *Rson);
	~TreeNode();
	User getUser();
	TreeNode *getLson();
	TreeNode *getRson();
	void setLson(TreeNode *lson);
	void setRson(TreeNode *rson);
};

#endif // TREENODE_H
