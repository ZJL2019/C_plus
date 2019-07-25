#include"BTree.h"

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