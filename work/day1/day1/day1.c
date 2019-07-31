#define _CRT_SECURE_NO_WARNINGS 1
//#define INT_PTR int*
//typedef int* int_ptr;
int SeekNum(int arr[][4])
{
	int n = 0;
	int i = 0;
	int j = 3;
	scanf("%d", &n);
	while ((j >= 0) && (i < 4))
	{
		if (arr[i][j] == n)
		{
			return 1;
		}
		else if (arr[i][j]<n)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return 0;
}


int main()
{
	/*int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
	int *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);*/

//******************************************************
	/*int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);*/
//*******************************************************
	/*INT_PTR a, b;
	int_ptr c, d;
	int f[1] = { 1};
	a = f[0];
	b = f[0];
	c = f[0];
	d = f[0];*/
//******************************************************
	/*int a[4][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	printf("%d\n", *(a[1] + 3));*/
//******************************************************
	int a[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	printf("%d\n", SeekNum(a));
	return 0;
}