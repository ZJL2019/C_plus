#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
typedef char BTDataType;

#define ENDTAG '#'

typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
}BTNode;

BTNode* BinaryTreeCreate(const BTDataType* a)
{
	BTNode* cur;
	static int i = 0;
	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = a[i];
	i++;
	cur->left = BinaryTreeCreate(a);
	cur->right = BinaryTreeCreate(a);
	return cur;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->left);
		printf("%c", root->data);
		BinaryTreeInOrder(root->right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->left);
		BinaryTreePostOrder(root->right);
		printf("%c", root->data);
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	std::queue<BTNode*> qu;
	BTNode* tmp;
	qu.push(root);
	while (!qu.empty())
	{
		tmp = qu.front();
		printf("%c", tmp->data);
		if (tmp->left)
		{
			qu.push(tmp->left);
		}
		if (tmp->right)
		{
			qu.push(tmp->right);
		}
		qu.pop();
	}
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	std::stack<BTNode*> st;
	BTNode* cur = root;
	while (cur || !st.empty())
	{
		printf("%c", cur->data);
		if (cur->right)
		{
			st.push(cur->right);
		}
		if (cur->left)
		{
			cur = cur->left;
		}
		else
		{
			if (st.empty())
			{
				break;
			}
			cur = st.top();
			st.pop();
		}
	}
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	std::stack<BTNode*>  st;
	BTNode* cur=root;
	while (cur || !st.empty())
	{
		for (cur; cur; cur = cur->left)
		{
			st.push(cur);
		}
		if (!st.empty())
		{
			cur = st.top();
			printf("%c", cur->data);
			st.pop();
			cur = cur->right;
		}
	}
}


void BinaryTreePostOrderNonR(BTNode* root)
{
	std::stack<BTNode*> st;
	BTNode* cur = root;
	int tag[32] = { 0 };
	while (cur || !st.empty())
	{
		for (cur; cur; cur = cur->left)
		{
			st.push(cur);
			tag[st.size()] = 0;
		}

		while (!st.empty() && tag[st.size()] == 1)
		{
			cur = st.top();
			printf("%c", cur->data);
			st.pop();
			cur = NULL;
		}

		if (!st.empty())
		{
			tag[st.size()] = 1;
			cur = st.top()->right;
		}
	}
}

int BinaryTreeComplete(BTNode* root)
{
	std::queue<BTNode*> qu;
	BTNode* tmp;
	int leafflag = 0;
	qu.push(root);
	while (!qu.empty())
	{
		tmp = qu.front();
		printf("%c", tmp->data);
		qu.pop();
		if (leafflag)
		{
			if (leafflag && (tmp->left || tmp->right))
			{
				return 0;
			}
			continue;
		}
		if (tmp->left&&tmp->right)
		{
			qu.push(tmp->left);
			qu.push(tmp->right);
		}
		else if (tmp->right && !tmp->left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->left)
			{
				qu.push(tmp->left);
			}
		}
	}
	return 1;
}

void BinaryTreeDestory(BTNode* root)
{
	BTNode* left, *right;
	if (root)
	{
		left = root->left;
		right = root->right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}

