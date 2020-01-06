#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Huffman树节点
template <class W>
struct HuffManTreeNode
{
	HuffManTreeNode(const W& weight = W())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_weight(weight)
	{
	}

	HuffManTreeNode <W>* _pLeft;
	HuffManTreeNode <W>* _pRight;
	HuffManTreeNode <W>* _pParent;
	W _weight;//结点权值
};

//优先级队列比较方法
template<class W>
class Less
{
	typedef HuffManTreeNode<W> Node;
public:
	bool operator()(const Node* pLeft,const Node* pRight)
	{
		return pLeft->_weight > pRight->_weight;
	}
};

//哈夫曼树
template <class W>
class HuffManTree
{
	typedef HuffManTreeNode<W> Node;
public:
	HuffManTree()
		:_pRoot(nullptr)
	{}

	HuffManTree(const vector<W>& vWeight, const W& invalid)
	{
		CreatHuffManTree(vWeight,invalid);
	}

	void CreatHuffManTree(const vector<W>& vWeight, const W& invalid)
	{
		priority_queue<Node*,vector<Node*>,Less<W>> q;
		for (auto e : vWeight)
		{
			if (e == invalid)
				continue;
			q.push(new Node(e));
		}

		while (q.size()>1)
		{
			Node* pLeft = q.top();
			q.pop();
			
			Node* pRight = q.top();
			q.pop();

			Node* pParent = new Node(pLeft->_weight + pRight->_weight);
			pParent->_pLeft = pLeft;
			pParent->_pRight = pRight;

			pLeft->_pParent = pParent;
			pRight->_pParent = pParent;

			q.push(pParent);
		}
		_pRoot = q.top();
	}

	Node* GetProot()
	{
		return _pRoot;
	}

	~HuffManTree()
	{
		_DestroyTree(_pRoot);
	}

private:
	void _DestroyTree(Node*& pRoot)
	{
		if (pRoot)
		{
			_DestroyTree(pRoot->_pLeft);
			_DestroyTree(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

private:
	Node* _pRoot;
};

