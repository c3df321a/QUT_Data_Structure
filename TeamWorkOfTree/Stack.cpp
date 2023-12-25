//stack.cpp
#pragma once
#include"Stack.h"







template <class DataType>
Stack <DataType> ::Stack()//初始化
{
	m_Head = nullptr;
	m_Top = 0;
}
template <class DataType>
void Stack <DataType>::Push(DataType Data)//入栈
{
	NODE<DataType>* node = new NODE<DataType>();
	node->m_Link = m_Head;
	m_Head = node;
	node->m_Data = Data;
	m_Top++;
}
template <class DataType>
DataType Stack <DataType> ::Pop()//出栈
{
	if (m_Top != 0)
	{
		DataType Data;
		struct NODE<DataType>* node = m_Head;
		Data = node->m_Data;
		//std::cout << node->m_Data << std::endl;
		m_Head = node->m_Link;
		delete node;
		m_Top--;
		return Data;
	}
	else
	{
		std::cout << "S no data" << std::endl;
		exit(-1);
	}
}
template <class DataType>
void Stack <DataType> ::StackTraverse()//遍历
{
	struct NODE* node = m_Head;
	while (node)
	{
		std::cout << node->m_Data << std::endl;
		node = node->m_Link;
	}
	std::cout << m_Top << std::endl;
}

template <class DataType>
bool Stack <DataType> ::IsEmpty()//检查是否为空
{
	if (!m_Head)
		return true;
	else
		return false;
}

template <class DataType>
DataType Stack <DataType> ::GetTop()//获得栈顶元素
{
	if (m_Head)
		return m_Head->m_Data;
	else
		return 0;
}

template <class DataType>
int Stack <DataType> ::GetLenth()//获取长度
{
	return m_Top;
}

