//PriorityQueue.cpp
#include"PriorityQueue.h"
#include<iostream>
template<class DataType>
PriorityQueue<DataType>::PriorityQueue()//构造
{
	m_Head = nullptr;
	m_Tail = nullptr;
}

template<class DataType>
void PriorityQueue<DataType>::Push(DataType Data, int weight)//入队
{
	PriorityQueueNode<DataType>* node = new PriorityQueueNode <DataType>();
	node->m_Data = Data;
	node->m_weight = weight;
	node->m_Link = nullptr;
	if (!m_Tail)
	{
		m_Tail = node; m_Head = node;
	}
	else
	{
		if (node->m_weight < m_Tail->m_weight)
		{
			node->m_Link = m_Tail;
			m_Tail = node;
		}
		else
		{
			PriorityQueueNode<DataType>* temp = m_Tail;
			while (temp != m_Head)
			{
				if (node->m_weight > temp->m_Link->m_weight)	temp = temp->m_Link;
				else break;
			}
			node->m_Link = temp->m_Link;
			temp->m_Link = node;
			if (temp == m_Head)	m_Head = node;
		}
	}
}

template<class DataType>
DataType PriorityQueue<DataType>::Pop()//出队
{
	if (m_Tail)
	{
		DataType temp;
		struct PriorityQueueNode<DataType>* node = m_Tail;
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
bool PriorityQueue<DataType>::IsEmpty()//判断是否为空
{
	if (!m_Tail)
		return true;
	else
		return false;
}
