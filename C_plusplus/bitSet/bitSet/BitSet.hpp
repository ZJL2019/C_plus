#pragma once

#include <bitset>
#include <iostream>
using namespace std;
//void TestBitSet()
//{
//	bitset<100> bs;
//	bs.set(12);
//	bs.set(24);
//	bs.set(29);
//
//	if (bs.test(12))
//	{
//		cout << "bs 12 is 1" << endl;
//	}
//	else
//	{
//		cout << "bs 12 is not 1" << endl;
//	}
//
//	cout << bs.size() << endl;
//	cout << bs.count() << endl;
//
//	bs.reset(12);
//	if (bs.test(12))
//	{
//		cout << "bs 12 is 1" << endl;
//	}
//	else
//	{
//		cout << "bs 12 is not 1" << endl;
//	}
//}


#include <vector>
namespace MBitSet
{
	template <size_t N>
	class bitset
	{
	public:
		bitset()
			:bit1count_(0)
		{
			bst_.resize((N >> 3) + 1);
		}

		bitset<N>& set(size_t pos)
		{
			if (pos >= N)
			{
				return *this;
			}
			size_t index = pos / 8;
			size_t which = pos % 8;

			bst_[index] |= (1 << which);
			bit1count_++;
			return *this;
		}

		bitset<N>& reset(size_t pos)
		{
			if(pos >= N)
			{
				return *this;
			}
			size_t index = pos / 8;
			size_t which = pos % 8;
			bst_[index] &= ~(1 << which);
			bit1count_--;
			return *this;
		}

		size_t size()const
		{
			return N;
		}

		size_t count()const
		{
			return bit1count_;
		}

		bool test(size_t pos)const
		{
			if (pos >= N)
			{
				return false;
			}
			size_t index = pos / 8;
			size_t which = pos % 8;

			return 0 != (bst_[index] & (1 << which));
		}

	private:
		vector<unsigned char> bst_;
		size_t bit1count_;
	};
}


void TestBitSet()
{
	MBitSet::bitset<100> bs;
	bs.set(12);
	bs.set(24);
	bs.set(29);

	if (bs.test(12))
	{
		cout << "bs 12 is 1" << endl;
	}
	else
	{
		cout << "bs 12 is not 1" << endl;
	}

	cout << bs.size() << endl;
	cout << bs.count() << endl;

	bs.reset(12);
	if (bs.test(12))
	{
		cout << "bs 12 is 1" << endl;
	}
	else
	{
		cout << "bs 12 is not 1" << endl;
	}
}