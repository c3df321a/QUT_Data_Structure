//BiTree.h
#pragma once
#include <iostream>



template <class DataType>
class BiTree
{
public:

    BiTree* CreatTree();
    void HeadTraversal(BiTree*);
    void MidTraversal(BiTree*);
    void TailTraversal(BiTree*);
    int Deep(BiTree*);
    void LevelOrderTraversal(BiTree*);
    DataType m_Data;
	BiTree* left;
    BiTree* right;
};



template <class DataType>
struct NODE
{
	struct NODE* m_Link;
	BiTree<DataType>* m_Data;
	NODE() {}
};

template <class DataType>
class Stack
{
public:
	Stack();
	void Push(BiTree<DataType>*);
	BiTree<DataType>* Pop();
	bool IsEmpty();
private:
	NODE<DataType>* m_Head;
	int m_Top;
};