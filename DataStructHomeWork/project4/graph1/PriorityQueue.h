#pragma once
//PriorityQueue.h
#pragma once
template <class DataType>
struct PriorityQueueNode
{
	struct PriorityQueueNode* m_Link;
	DataType m_Data;
	int m_weight;
	PriorityQueueNode() {}
};

template <class DataType>
class PriorityQueue
{
public:
	PriorityQueue();
	void Push(DataType, int);
	DataType Pop();
	bool IsEmpty();
private:
	PriorityQueueNode <DataType>* m_Head;
	PriorityQueueNode <DataType>* m_Tail;
};


