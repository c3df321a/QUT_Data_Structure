//line.cpp
#include"Line.h"
#include<iostream>
template<class DataType>
Line<DataType>::Line()//����
{
	m_Head = nullptr;
	m_Tail = nullptr;
}

template<class DataType>
void Line<DataType>::Push(DataType Data)//���
{
	LINENODE<DataType>* node = new LINENODE <DataType>();
	node->m_Data = Data;
	node->m_Link = nullptr;
	if (!m_Tail)
	{
		m_Tail = node; m_Head = node;
	}
	else
	{
		m_Head->m_Link = node;
		m_Head = node;
	}
}

template<class DataType>
DataType Line<DataType>::Pop()//����
{
	if(m_Tail)
	{
		DataType temp;
		struct LINENODE<DataType>* node = m_Tail;
		temp = node->m_Data;
		m_Tail = node->m_Link;
		delete node;
		return temp;
	}
	else
	{
		std::cout << "L no data"; exit(-1);
	}
}


template<class DataType>
bool Line<DataType>::IsEmpty()//�ж��Ƿ�Ϊ��
{
	if (!m_Tail)
		return true;
	else
		return false;
}
