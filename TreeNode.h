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
    tnode Lson;
    tnode Rson;
public:
	TreeNode(User u, tnode Lson, tnode Rson);
	~TreeNode();
	User getUser();

};
typedef TreeNode* tnode;
#endif // TREENODE_H
