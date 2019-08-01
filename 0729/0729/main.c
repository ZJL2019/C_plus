#include"sort.h"
#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 5, 1, 8, 7, 3, 2, 9, 4, 6 };
	//1,5,3,11,4,9,8,2,7
	//MergeSort(a, ARRSIZE(a));
	//QSort(a, ARRSIZE(a));
	//BubbleSort(a, ARRSIZE(a));
	//SelectSort(a, ARRSIZE(a));
	//Qsort2(a, ARRSIZE(a));//ÍÚ¿Ó·¨
	//Qsort3(a, ARRSIZE(a));
	//InsertSort(a, ARRSIZE(a));
	//ShellSort(a, ARRSIZE(a));
	QSortNR(a, ARRSIZE(a));
	printArray(a, ARRSIZE(a));
	system("pause");
	return 0;
}