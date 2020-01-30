#include "BTree.hpp"

int main()
{
	BTNode* testTree = BinaryTreeCreate("ABD##E#H##CF##G##");
	BinaryTreePrevOrder(testTree);
	printf("\n");
	BinaryTreeInOrder(testTree);
	printf("\n");
	BinaryTreePostOrder(testTree);
	printf("\n");
	BinaryTreeLevelOrder(testTree);
	printf("\n");
	BinaryTreePrevOrderNonR(testTree);
	printf("\n");
	BinaryTreeInOrderNonR(testTree);
	printf("\n");
	BinaryTreePostOrderNonR(testTree);
	printf("\n");
	printf("%d\n", BinaryTreeComplete(testTree));
	return 0;
}