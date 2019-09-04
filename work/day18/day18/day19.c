#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	/*int a = 5, *p = &a, *q = &a;*/
	//*********************************************
	/*int a[][3] = { 1, 2, 3, 4, 5, 6, 7 };*/

	//*********************************************
	//int x = 4;
	//printf("%d", x += x *= x + x); //(4*4)+16+32

	//*********************************************
	char str[] = { "xxxyyyyz" };
	int count = 1;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			if (count != 1)
				printf("%d", count);
			printf("%c", str[i]);
			count = 1;
		}
		i++;
	}
	return 0;
}