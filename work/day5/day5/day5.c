#define _CRT_SECURE_NO_WARNINGS 1

#define CIR(r) r*r
int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);//依次去除x二进制最后一位为1的位数
	}
	return count;
}

unsigned long g_ulGlobal = 0;
void GlobalInin(unsigned  long ulArg)
{
	ulArg = 0x01;
	return;
}

SListNode* SearchlistNode(*phead)
{
	SListNode*tmp;
	int n=0;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		n++;
	}
	int j = 1;
	for (tmp = phead; tmp; tmp = tmp->next,j++)
	{
		if (j == n - k + 1)
		{
			return tmp;
		}
	}
}

int main()
{
	/*printf("fun(2017)=%d\n", fun(2019));*/
//**************************************************
	//int a = 1;
	//int b = 2;
	//int t;
	//t = CIR(a + b);//a+b*a+b
	//printf("%d\n", t);
//**************************************************
	GlobalInin(g_ulGlobal);
	printf("%lu", g_ulGlobal);
	return 0;
}