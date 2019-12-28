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

	}


private:
	Node* _pRoot;
};