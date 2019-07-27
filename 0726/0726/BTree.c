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
	QueueDestory(&qu);
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

void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);
	while (cur || StackIsEmpty(&st))
	{
		for (; cur; cur = cur->left)
		{
			StackPush(&st, cur);
		}

		if (StackIsEmpty(&st))
		{
			cur = StackFront(&st);
			putchar(cur->data);
			StackPop(&st);
			cur = cur->right;
		}
	}
	StackDestory(&st);
}


void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	BTNode *cur = root;
	int tag[32] = { 0 };
	StackInit(&st, 100);
	while (cur || StackIsEmpty(&st))
	{
		for (; cur; cur = cur->left)
		{
			StackPush(&st, cur);
			tag[st.size] = 0;
		}

		while (StackIsEmpty(&st) && tag[st.size] == 1)
		{
			cur = StackFront(&st);
			putchar(cur->data);
			StackPop(&st);
			cur = NULL;
		}

		if (StackIsEmpty(&st))
		{
			tag[st.size] = 1;
			cur = StackFront(&st)->right;
		}
	}
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode*tmp;
	int leafflag = 0;
	QueueInit(&qu);
	QueuePush(&qu, root);

	while (QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		if (leafflag && (tmp->left || tmp->right))
		{
			return 0;
		}
		if (tmp->left&&tmp->right)
		{
			QueuePush(&qu, tmp->left);
			QueuePush(&qu, tmp->right);
		}
		else if (tmp->right&&!tmp->left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->left)
			{
				QueuePush(&qu, tmp->left);
			}
		}
		
		QueuePop(&qu);
	}
	return 1;
	QueueDestory(&qu);
}