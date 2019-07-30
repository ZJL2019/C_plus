#include"sort.h"

void dealMergeSort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(arr, tmp, 0, mid);
	dealMergeSort(arr, tmp, mid + 1, end);
	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end; c++)
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
	for (; a <= mid; a++, c++)
	{
		tmp[c] = arr[a];
	}
	for (; b <= end; b++, c++)
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


void dealQsort(int *arr, int start, int end)
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


void BubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				SwapArgs(arr + j, arr + j + 1);
			}
		}
	}
}


void SelectSort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
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

void Qsort2(int *arr, int n)//ÍÚ¿Ó·¨
{
	dealQsort2(arr, 0, n - 1);

}
void dealQsort2(int *arr, int start, int end)
{
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	int tmp = arr[start];
	int i = start, j = end;
	while (i<j)
	{

		if (flag&&tmp>arr[j])
		{
			arr[i] = arr[j];
			flag = !flag;
		}
		if (!flag&&tmp < arr[i])
		{
			arr[j] = arr[i];
			flag = !flag;
		}
		flag ? j-- : i++;
	}
	arr[i] = tmp;
	dealQsort(arr, start, i - 1);
	dealQsort(arr, i + 1, end);
}

int Partition(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	if (arr[start] > arr[mid])
	{
		SwapArgs(arr + start, arr + mid);
	}
	if (arr[mid] > arr[end])
	{
		SwapArgs(arr + mid, arr + end);
	}
	if (arr[start] > arr[mid])
	{
		SwapArgs(arr + start, arr + mid);
	}
	SwapArgs(arr + mid, arr + end - 1);
	int i = start + 1;
	int j = end - 2;
	while (i < j)
	{
		while (arr[i] <arr[end - 1])
		{
			i++;
		}
		while (arr[j] >arr[end - 1])
		{
			j--;
		}
		SwapArgs(arr + i, arr + j);
	}
	if (end - start <= 2)
	{
		return mid;
	}
	SwapArgs(arr + i, arr + end - 1);
	return i;
}
void dealQsort3(int *arr, int start, int end)
{
	if (end - start>INSERT_SORT_LENTH)
	{
		int pivot = Partition(arr, start, end);
		dealQsort3(arr, start, pivot - 1);
		dealQsort3(arr, pivot + 1, end);
	}
	else
	{
		InsertSort(arr + start, end - start + 1);
	}
}
void Qsort3(int *arr, int n)//hoare
{
	dealQsort3(arr, 0, n - 1);
}

void InsertSort(int *arr, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = arr[i];
		for (j = i; j>0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

void ShellSort(int *arr, int n)
{
	int i, j, k;
	int tmp;
	int gap = n / 2;
	for (; gap > 0; gap /= 2)
	{
		for (k = 0; k<gap; k++)
		{
			for (i = k+gap; i < n; i += gap)
			{
				tmp = arr[i];
				for (j = i; j>0 && arr[j - gap] > tmp; j-=gap)
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}