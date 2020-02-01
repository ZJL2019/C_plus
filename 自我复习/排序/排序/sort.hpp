#pragma once
#define INSERT_SORT_LENTH 5
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
//直接插入
void InsertSort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j;
		int tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

//选择
void SelectSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

//冒泡
void BubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//希尔
void ShellSort(int *arr, int n)
{
	int  gap = n / 2;
	for (; gap > 0; gap /= 2)
	{
		for (int k = 0; k < gap; k++)
		{
			for (int i = k + gap; i < n; i += gap)
			{
				int j;
				int tmp = arr[i];
				for (j = i; j > 0 && arr[j - gap] > tmp; j -= gap)
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}

//归并
void dealMergeSort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(arr, tmp, start, mid);
	dealMergeSort(arr, tmp, mid + 1, end);
	int a = start;
	int b = mid + 1;
	int c = a;
	for (; a <= mid && b <= end; c++)
	{
		if (arr[a] > arr[b])
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
	for (int i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeSort(int *arr, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	dealMergeSort(arr,tmp, 0, n - 1);
	free(tmp);
}

//快排
void dealQsort(int *arr, int start, int end)
{
	int flag = 1;
	if (start > end)
	{
		return;
	}
	int i = start, j = end;
	while (i<j)
	{
		if (arr[i] > arr[j])
		{
			std::swap(arr[i], arr[j]);
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



//挖坑快排
void dealQsort2(int *arr, int start, int end)
{
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	int tmp = arr[start];
	int i = start, j = end;
	while (i < j)
	{
		if (flag&&tmp > arr[j])
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
	dealQsort2(arr, start, i - 1);
	dealQsort2(arr, i + 1, end);
}
void QSort2(int *arr, int n)
{
	dealQsort2(arr, 0, n - 1);
}

//hoare
int Partition(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	if (arr[start] > arr[mid])
	{
		std::swap(arr[start], arr[mid]);
	}
	if (arr[mid] > arr[end])
	{
		std::swap(arr[mid], arr[end]);
	}
	if (arr[start] > arr[mid])
	{
		std::swap(arr[start], arr[mid]);
	}
	if (end - start <= 2)
	{
		return mid;
	}
	std::swap(arr[mid], arr[end - 1]);
	int i = start + 1;
	int j = end - 2;
	while (arr[i] < arr[end - 1])
	{
		i++;
	}
	while (arr[j] > arr[end - 1])
	{
		j--;
	}
	while (i < j)
	{
		std::swap(arr[i], arr[j]);
		j--, i++;
		while (arr[i] < arr[end - 1])
		{
			i++;
		}
		while (arr[j] > arr[end - 1])
		{
			j--;
		}
	}
	std::swap(arr[i], arr[end - 1]);
	return i;
}
void dealQsort3(int *arr, int start, int end)
{
	if (end - start > INSERT_SORT_LENTH)
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
void Qsort3(int *arr, int n)
{
	dealQsort3(arr, 0, n - 1);
}

//快排非递归
void QuickSortNonR(int* arr, int left, int right)
{
	std::stack<int> st;
	st.push(left);
	st.push(right);
	while (!st.empty())
	{
		int end = st.top();
		st.pop();
		int begin = st.top();
		st.pop();
		int div = Partition(arr, begin, end);
		if (begin < div - 1)
		{
			st.push(begin);
			st.push(div - 1);
		}
		if (div + 1 < end)
		{
			st.push(div + 1);
			st.push(end);
		}
	}
}
void QSortNR(int *arr, int n)
{
	QuickSortNonR(arr, 0, n - 1);
}
//输出
void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}