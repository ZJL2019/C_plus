//45840 - 不要二

//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。

#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int W, H;
	while (cin >> W >> H)
	{
		char a[1000][1000] = { 0 };
		int ret = 0;
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (a[i][j] == 0)
				{
					ret++;
					if (i + 2 < W)
					{
						a[i + 2][j] = 'N';
					}
					if (j + 2 < H)
					{
						a[i][j + 2] = 'N';
					}
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}