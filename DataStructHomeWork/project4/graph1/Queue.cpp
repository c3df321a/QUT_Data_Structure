//Queue.cpp
#pragma once
#include"Queue.h"
#include<iostream>
template<class DataType>
Queue<DataType>::Queue()//����
{
	m_Head = nullptr;
	m_Tail = nullptr;
}

template<class DataType>
void Queue<DataType>::Push(DataType Data)//���
{
	QueueNode<DataType>* node = new QueueNode <DataType>();
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
DataType Queue<DataType>::Pop()//����
{
	if (m_Tail)
	{
		DataType temp;
		struct QueueNode<DataType>* node = m_Tail;
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
bool Queue<DataType>::IsEmpty()//�ж��Ƿ�Ϊ��
{
	if (!m_Tail)
		return true;
	else
		return false;
}
