#include "heap.hpp"
#define ARRAIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 1, 6, 3, 7, 9, 8 };
	Heap hp;
	HeapInit(&hp, a, ARRAIZE(a));
	HeapPush(&hp, 10);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d,%d\n", HeapTop(&hp), HeapSize(&hp));
	HeapSort(&hp);
	for (int i = 0; i < HeapSize(&hp); i++)
	{
		printf("%d ", hp._data[i]);
	}
	HeapDestory(&hp);
	return 0;
}