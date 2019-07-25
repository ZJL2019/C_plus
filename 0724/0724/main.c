#include"BTree.h"
#include"queue.h"

int main()
{
	BTNode * testTree = BinaryTreeCreate("ABD##E#H##CF##G##");
	BinaryTreePrevOrder(testTree);
	printf("\n");
	BinaryTreeInOrder(testTree);
	printf("\n");
	BinaryTreePostOrder(testTree);
	printf("\n");
	BinaryTreeLevelOrder(testTree);
	printf("\n");
	system("pause");
	return 0;
}
