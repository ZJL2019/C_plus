#include"sort.h"

void dealMergeSort(int *arr, int *tmp,int start,int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(arr, tmp, 0, mid);
	dealMergeSort(arr, tmp, mid+1, end);
	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end;c++)
	{
		if (arr[a] >= arr[b])
		{
			tmp[c] = arr[b];
			b++;
		}
		else
		{
			tmp[c] = arr[a];
			a++;
		}
	}
	for (; a <= mid;a++,c++)
	{
		tmp[c] = arr[a];
	}
	for (; b<= end; b++, c++)
	{
		tmp[c] = arr[b];
	}
	int i;
	for (i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}


void MergeSort(int *arr, int n)
{
	int*tmp = (int*)malloc(n*sizeof(int));
	dealMergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}


void dealQsort(int *arr,int start,int end)
{
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	int i = start, j = end;
	while (i<j)
	{
		
		if (arr[i]>arr[j])
		{
			SwapArgs(arr + i, arr + j);
			flag = !flag;
		}
		flag ? j-- : i++;
	}
	dealQsort(arr, start, i - 1);
	dealQsort(arr, i + 1, end);
}


void QSort(int *arr, int n)
{
	dealQsort(arr, 0, n - 1);
}


void dealBubbleSort(int *arr,int n)
{
	int i,j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				SwapArgs(arr+j, arr+j + 1);
			}
		}
	}
}


void BubbleSort(int *arr, int n)
{
	dealBubbleSort(arr, n);
}


void dealSelectSort(int *arr, int n)
{
	int i,j;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i]>arr[j])
			{
				SwapArgs(arr + i, arr + j);
			}
		}
	}
}


void SelectSort(int *arr, int n)
{
	dealSelectSort(arr, n);
}


void SwapArgs(int *a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void printArray(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}