#include"BTree.h"
#include"queue.h"
#include"Stack.h"
BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode*cur;
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
	Queue qu;
	BTNode*tmp;

	QueueInit(&qu);
	QueuePush(&qu, root);

	while (QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->data);
		if (tmp->left)
		{
			QueuePush(&qu, tmp->left);
		}
		if (tmp->right)
		{
			QueuePush(&qu, tmp->right);
		}
		QueuePop(&qu);
	}
}

void BinaryTreePrevOrderNonR(BTNode* root)	
{
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);

	while (cur||StackIsEmpty(&st))
	{
		putchar(cur->data);
		if (cur->right)
		{
			StackPush(&st, cur->right);
		}
		if (cur->left)
		{
			cur = cur->left;
		}
		else
		{
			cur=StackFront(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}