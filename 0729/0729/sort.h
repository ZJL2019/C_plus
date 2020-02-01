#ifndef _SORT_H_
#define _SORT_H_
#define INSERT_SORT_LENTH 5
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

void MergeSort(int *arr, int n);
void dealMergeSort(int *arr, int *tmp, int start, int end);
void QSort(int *arr, int n);
void dealQsort(int *arr, int start, int end);
void SwapArgs(int *a, int*b);
void BubbleSort(int *arr, int n);
void SelectSort(int *arr, int n);
void Qsort2(int *arr, int n);
void dealQsort2(int *arr, int start, int end);
void printArray(int *arr, int n);
int Partition(int *arr, int start, int end);
void dealQsort3(int *arr, int start, int end);
void Qsort3(int *arr, int n);//hoare
void InsertSort(int *arr, int n);
void ShellSort(int *arr, int n);
void QuickSortNonR(int* arr, int left, int right);
void QSortNR(int *arr, int n);


#endif /*_SORT_H_*/