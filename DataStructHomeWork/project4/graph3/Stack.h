#pragma once
#pragma once
#include<iostream>
#include<CString>
template <class DataType>
struct NODE
{
	struct NODE* m_Link;
	DataType m_Data;
	NODE() {}
};

template <class DataType>
class Stack
{
public:
	Stack();
	void Push(DataType);
	DataType Pop();
	DataType GetTop();
	bool IsEmpty();
private:
	NODE<DataType>* m_Head;
	int m_Top;
};