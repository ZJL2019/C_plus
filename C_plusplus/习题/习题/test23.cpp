//24951 - 二进制插入
//有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位, 其中二进制的位数从低位数到高位且以0开始。
//
//给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i - j + 1。


class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		vector<int> vi;
		int ret = 0;
		for (int k = n; k; k /= 2)
		{
			vi.push_back(k % 2);
		}
		for (int k = m; k&&j <= i; k /= 2)
		{
			vi[j] = k % 2;
			j++;
		}
		for (int k = 0; k<vi.size(); k++)
		{
			ret += vi[k] * pow(2, k);
		}
		return ret;
	}
};