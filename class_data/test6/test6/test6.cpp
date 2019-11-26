#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 8
#define M 2*N-1
#define MAX 10000

typedef char TElemType;

//顺序存储结构
typedef struct{
	TElemType data;
	unsigned int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef HTNode HuffmanTree[M + 1];

typedef struct
{
	char ch;
	char bits[N + 1];
	int len;
}CodeNode;

typedef CodeNode HuffmanCode[N + 1];

void creatHuffmanTree(HuffmanTree HT, HuffmanCode HC, int *w, int n, char str[])
{
	int i;
	void select(HuffmanTree HT, int k, int &s1, int &s2);
	if (n <= 1)
		return;
	for (i = 1; i <= n; i++)
	{
		HT[i].weight = w[i];
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= M; i++)
	{
		HT[i].weight = 0;
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= M; i++)
	{
		int s1, s2;
		select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for (i = 0; i <= n; i++)
	{
		HC[i].ch = str[i];
	}
}


void select(HuffmanTree HT, int k, int &s1, int &s2)
{
	unsigned int tmp = MAX, tmpi = 0;
	int i;
	for (i = 1; i <= k; i++)
	{
		if (!HT[i].parent)
		{
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;
				tmpi = i;
			}
		}
	}
	s1 = tmpi;
	tmp = MAX;
	tmpi = 0;
	for (i = 1; i <= k; i++)
	{
		if ((!HT[i].parent) && i != s1)
		{
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;
				tmpi = i;
			}
		}
	}
	s2 = tmpi;
}


void printHuffmanTree(HuffmanTree HT, char ch[])
{
	printf("\n");
	printf("	data,weight,parent,lchild,rchild\n");
	for (int i = 1; i <= M; i++)
	{
		if (i > N)
		{
			printf("	-, %5d, %5d, %5d, %5d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
		else
		{
			printf("	%c, %5d, %5d, %5d, %5d\n", ch[i], HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
	}
	printf("\n");
}

void encodingHuffmanCode(HuffmanTree HT, HuffmanCode HC)
{
	char tmp[N];
	tmp[N - 1] = '\0';
	int start, c, f;
	for (int i = 1; i <= N; i++)
	{
		start = N - 1;
		c = i;
		f = HT[i].parent;
		while (f)
		{
			if (HT[f].lchild == c)
			{
				tmp[--start] = '0';
			}
			else
			{
				tmp[--start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		strcpy(HC[i].bits, &tmp[start]);
		HC[i].len = N - start;
	}
}

void printHuffmanCoding(HuffmanCode HC, char ch[])
{
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("%c:%s\n", ch[i], HC[i].bits);
	}
	printf("\n");
}

void coding(HuffmanCode HC, char *str)
{
	int i, j;
	while (*str)
	{
		for (i = 1; i <= N; i++)
			if (HC[i].ch == *str)
			{
				printf("%s", HC[i].bits);
				break;
			}
		str++;
	}
	printf("\n");
}

void decodingHuffmanCode(HuffmanTree HT, char *ch, char testDecodingStr[], int len, char *result)
{
	int p = M;
	int i = 0;
	int j = 0;
	while (i < len)
	{
		if (testDecodingStr[i] == '0')
		{
			p = HT[p].lchild;
		}
		if (testDecodingStr[i] == '1')
		{
			p = HT[p].rchild;
		}
		if (p <= N)
		{
			result[j] = ch[p];
			j++;
			p = M;
		}
		i++;
	}
	result[j] = '\0';
}

int main()
{
	HuffmanTree HT;
	TElemType ch[N + 1];
	int w[N + 1];
	printf("请输入%d个字符以及该字符对应的权值（如：a,5):\n", N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%c,%d", &ch[i], &w[i]);
		getchar();
	}

	HuffmanCode HC;
	creatHuffmanTree(HT, HC, w, N, ch);
	printHuffmanTree(HT, ch);
	encodingHuffmanCode(HT, HC);
	printHuffmanCoding(HC, ch);
	char *str = "abaccda";
	printf("%s的编码是：", str);
	coding(HC, str);
	char testDecodingStr[] = "00011000011110111011110001";
	int testDecodingStrLen = 26;
	printf("编码%s对应的字符串是：", testDecodingStr);
	char result[30];
	decodingHuffmanCode(HT, ch, testDecodingStr, testDecodingStrLen, result);
	printf("%s\n", result);
	return 0;
}


