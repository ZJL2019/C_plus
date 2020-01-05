#pragma once
#include<iostream>
using namespace std;

// binary search tree
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{
	}
	BSTNode<T> *_pLeft;
	BSTNode<T> *_pRight;
	T _data;
};


template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		//空树
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		//非空
		//1、按照二叉搜索树的特性，找待插入结点在树中的位置
		Node *pCur = _pRoot;
		Node *pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data)
			{
				pCur = pCur->_pRight;
			}
			else
			{
				return false;
			}
		}
		//2、插入新节点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}


	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		
		//找待删除结点的位置
		Node *pCur = _pRoot;
		Node *pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if(data<pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		if (nullptr == pCur)
			return false;
		Node* pDelNode = pCur;
		//pCur可能是叶子结点 || 只有右孩子
		if (nullptr == pCur->_pLeft)
		{
			if (nullptr == pParent)
			{
				//pCur是根节点
				_pRoot = pCur->_pRight;
			}

			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)
		{
			if (nullptr == pParent)
				_pRoot = pCur->_pLeft;
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
			}
		}
		else
		{
			//左右孩子均存在
			//在pCur的右子树中找一个代替结点-->一定是右子树中最小的结点（最左侧结点）
			Node* pDel = pCur->_pRight;
			pParent = pCur;
			while (pDel->_pLeft)
			{
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;
			//删除代替结点pDel

			if (pParent->_pLeft == pDel)
				pParent->_pLeft = pDel->_pRight;
			else
				pParent->_pRight = pDel->_pRight;

			pDelNode = pDel;
		}
		delete pDelNode;
		return true;
	}


private:
	Node* _pRoot;
};