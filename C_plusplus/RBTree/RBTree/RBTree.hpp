#pragma once

enum Color{RED,BLACK};

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& val,Color color=RED)
		:pLeft_(nullptr)
		,pRight_(nullptr)
		,pParent_(nullptr)
		,color_(color)
	{}

	RBTreeNode* pLeft_;
	RBTreeNode* pRight_;
	RBTreeNode* pParent_;
	T val_;
	Color color_;
};

template <class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		pHead_ = new Node;
		pHead_->pLeft_ = pHead_;
		pHead_->pRight_ = pHead_;
	}

	bool insert(const T& val)
	{
		Node*& pRoot = getRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
			pHead_->pLeft_ = pRoot;
			pHead_->pRight_ = pRoot;
			pRoot->pParent_ = pHead_;
			return true;
		}

		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (val < pCur->val_)
			{
				pCur = pCur->pLeft_;
			}
			else if (val > pCur->val_)
			{
				pCur = pCur->pRight_;
			}
			else
			{
				return false;
			}
		}

		pCur = new Node(val);

		if (val < pParent->val_)
			pParent->pLeft_ = pCur;
		else
			pParent->pRight_ = pCur;

		pCur->pParent_ = pParent;

		if (pParent->color_ == RED)
		{

		}

		pHead_->pLeft_ = LeftMost();
		pHead_->pRight_ = RightMost();

		return true;
	}

private:

	Node* RightMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pRight_)
		{
			pCur = pCur->pRight_;
		}

		return pCur;
	}

	Node* LeftMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
			return pHead_;

		Node* pCur = pRoot;
		while (pCur->pLeft_)
		{
			pCur = pCur->pLeft_;
		}
		
		return pCur;
	}

	Node*& getRoot()
	{
		return	pHead_->pParent_;
	}

private:
	Node* pHead_;
};