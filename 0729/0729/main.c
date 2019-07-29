#include"sort.h"
#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 9,10,6,2,15,6,4,8,6,7 };
	//MergeSort(a, ARRSIZE(a));
	//QSort(a, ARRSIZE(a));
	//BubbleSort(a, ARRSIZE(a));
	SelectSort(a, ARRSIZE(a));
	printArray(a, ARRSIZE(a));
	system("pause");
	return 0;
}