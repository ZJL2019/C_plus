#ifndef _SORT_H_
#define _SORT_H_
#include<stdio.h>
#include<stdlib.h>

void dealMergeSort(int *arr, int *tmp, int start, int end);
void MergeSort(int *arr, int n);
void printArray(int *arr, int n);
void QSort(int *arr, int n);
void SwapArgs(int *a, int*b);
void dealQsort(int *arr, int start, int end);
void BubbleSort(int *arr, int n);
void dealBubbleSort(int *arr,int n);
void SelectSort(int *arr, int n);
void dealSelectSort(int *arr, int n);

#endif /*_SORT_H_*/