#pragma once
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		:pLeft_(nullptr)
		,pRight_(nullptr)
		,pParent_(nullptr)
		,data_(data)
		,bf_(0)
	{}

	AVLTreeNode<T>* pLeft_;
	AVLTreeNode<T>* pRight_;
	AVLTreeNode<T>* pParent_;
	T data_;
	int bf_;
};


template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:pRoot_(nullptr)
	{}
	
	bool Insert(const T& data)
	{
		//空树
		if (nullptr == pRoot_)
		{
			pRoot_ = new Node(data);
			return true;
		}

		//非空，找到插入位置
		Node* pCur = pRoot_;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->data_)
			{
				pCur = pCur->pLeft_;
			}
			else if (data > pCur->data_)
			{
				pCur = pCur->pRight_;
			}
			else
			{
				return false;
			}
		}
		//插入新节点
		pCur = new Node(data);
		if (data < pParent->data_)
		{
			pParent->pLeft_ = pCur;
		}
		else
		{
			pParent->pRight_ = pCur;
		}
		pCur->pParent_ = pParent;

		//更新pParent的平衡因子
		while (pParent)
		{
			if (pCur == pParent->pLeft_)
			{
				pParent->bf_--;
			}
			else
			{
				pParent->bf_++;
			}
			if (0 == pParent->bf_)
			{
				return true;
			}
			else if (-1 == pParent->bf_ || 1 == pParent->bf_)
			{
				pCur = pParent;
				pParent = pCur->pParent_;
			}
			else
			{
				if (pParent->bf_ == 2)
				{
					//pParent的右子树高
					if (pCur->bf_ == 1)
					{
						RotateL(pParent);
					}
					else
					{
						RotateRL(pParent);
					}
				}
				else
				{
					//pParent的左子树高
					if (pCur->bf_ == -1)
					{
						RotateR(pParent);
					}
					else
					{
						RotateLR(pParent);
					}
				}
				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(pRoot_);
	}

	bool IsValidAVLTree()
	{
		return _IsValidAVLTree(pRoot_);
	}

private:

	bool _IsValidAVLTree(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return true;
		}

		int leftHegiht = Height(pRoot->pLeft_);
		int rightHeight = Height(pRoot->pRight_);
		int bf = rightHeight - leftHegiht;

		if (abs(bf) > 1 || bf != pRoot->bf_)
		{
			return false;
		}
		return _IsValidAVLTree(pRoot->pLeft_) && _IsValidAVLTree(pRoot->pRight_);
	}

	int Height(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return 0;
		}
		int leftHeight = Height(pRoot->pLeft_);
		int rightHeight = Height(pRoot->pRight_);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->pLeft_);
			cout << pRoot->data_ << " ";
			_InOrder(pRoot->pRight_);
		}
	}

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->pLeft_;
		Node* pSubLR = pSubL->pRight_;

		pParent->pLeft_ = pSubLR;
		if (pSubLR)
		{
			pSubLR->pParent_ = pParent;
		}
		pSubL->pRight_ = pParent;
		Node* pPParent = pParent->pParent_;
		pSubL->pParent_ = pPParent;
		pParent->pParent_ = pSubL;

		if (nullptr == pPParent)
		{
			pRoot_ = pSubL;
		}
		else
		{
			if (pPParent->pLeft_ == pParent)
			{
				pPParent->pLeft_ = pSubL;
			}
			else
			{
				pPParent->pRight_ = pSubL;
			}
		}
		pParent->bf_ = pSubL->bf_ = 0;
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->pRight_;
		Node* pSubRL = pSubR->pLeft_;

		pParent->pRight_ = pSubRL;
		if (pSubRL)
		{
			pSubRL->pParent_ = pParent;
		}
		pSubR->pLeft_ = pParent;
		Node* pPParent = pParent->pParent_;
		pSubR->pParent_ = pPParent;
		pParent->pParent_ = pSubR;

		if (nullptr == pPParent)
		{
			pRoot_ = pSubR;
		}
		else
		{
			if (pParent == pPParent->pLeft_)
			{
				pPParent->pLeft_ = pSubR;
			}
			else
			{
				pPParent->pRight_ = pSubR;
			}
		}
		pParent->bf_ = pSubR->bf_ = 0;
	}

	void RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->pRight_;
		Node*pSubRL = pSubR->pLeft_;
		int bf = pSubRL->bf_;
		
		RotateR(pParent->pRight_);
		RotateL(pParent);

		if (bf == 1)
		{
			pParent->bf_ = -1;
		}
		else if (bf == -1)
		{
			pSubR->bf_ = 1;
		}
	}

	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->pLeft_;
		Node* pSubLR = pSubL->pRight_;
		int bf = pSubLR->bf_;

		RotateL(pParent->pLeft_);
		RotateR(pParent);

		if (bf == 1)
		{
			pSubL->bf_ = -1;
		}
		else if (bf == -1)
		{
			pParent->bf_ = 1;
		}
	}

private:
	Node* pRoot_;
};

void TestAVLTree()
{
	int array[] = { 16,3,7,11,9,26,18,14,15 };
	AVLTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	
	t.InOrder();

	if (t.IsValidAVLTree())
	{
		cout << "t is valid avl tree" << endl;
	}
	else
	{
		cout << "t is not valid avl tree" << endl;
	}
}