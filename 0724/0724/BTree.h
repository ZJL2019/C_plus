#ifndef _BTREE_H_
#define _BTREE_H_

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;

#define ENDTAG '#'

typedef struct BinaryTreeNode{
	BTDataType data;
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
}BTNode;
BTNode* BinaryTreeCreate(BTDataType* a);
#endif /*_BTREE_H_*/