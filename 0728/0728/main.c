#include"heap.h"
#define ARRAIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 1, 6, 3, 7, 9, 8 };
	Heap hp;
	HeapInit(&hp, a, ARRAIZE(a));
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	HeapSort(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);

	system("pause");
	return 0;
}
