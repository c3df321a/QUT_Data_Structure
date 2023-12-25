//line.h
#pragma once
template <class DataType>
struct LINENODE
{
	struct LINENODE* m_Link;
	DataType m_Data;
	LINENODE() {}
};

template <class DataType>
class Line
{
public:
	Line();
	void Push(DataType);
	DataType Pop();
	bool IsEmpty();
private:
	LINENODE <DataType>* m_Head;
	LINENODE <DataType>* m_Tail;
};


