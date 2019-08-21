#define _CRT_SECURE_NO_WARNINGS 1
struct student
{
	char name[10];
	int age;
	char gender;
}std[3],*p=std;

int main()
{
	//scanf("%d", &(*p).age);
	//scanf("%d", &std[0].gender);
	//scanf("%d", &(p->gender));
	////scanf("%d", &std.name)/    ´íÎó

//*******************************************
	/*int a = 2, *p1, **p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d,%d,%d", a, *p1, **p2);*/

//*******************************************
	/*int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
		{
			s += j;
		}
	}
	printf("%d", s);*/

//*******************************************
	/*int arr[] = { 6, 7, 8, 9, 10 };
	int *ptr = arr;
	*(ptr++) += 123;
	printf("%d %d", *ptr, *(++ptr));*/

//*******************************************
	int a = 0;
	scanf("%d", &a);//12321
	int i,sum=0;
	for (i = a; i; i /= 10)
	{
		sum = sum * 10 + i % 10;
	}
	if (sum == a)
	{
		printf("yes");
	}
	else
		printf("no");

 	return 0;

}