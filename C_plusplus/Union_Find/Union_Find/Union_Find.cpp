#include<iostream>
#include<vector>
using namespace std;
class UnionFindSet
{
public:
	UnionFindSet(size_t N)
	{
		_a.resize(N, -1);
	}

	int FindRoot(int x)
	{
		while (_a[x] >= 0)
		{
			x = _a[x];
		}
		return x;
	}

	void Union(int x1,int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			_a[root1] += _a[root2];
			_a[root2] = root1;
		}
	}
private:
	vector<int> _a;
};