#pragma once
//Queue.h
template <class DataType>
struct QueueNode
{
	struct QueueNode* m_Link;
	DataType m_Data;
	QueueNode() {}
};

template <class DataType>
class Queue
{
public:
	Queue();
	void Push(DataType);
	DataType Pop();
	bool IsEmpty();
private:
	QueueNode <DataType>* m_Head;
	QueueNode <DataType>* m_Tail;
};


