#include<iostream>
#include"Stack.cpp"

struct VEX
{
	int InDegree;
	int OutDegree;
	int m_num;
	struct ARC* m_Next;
	VEX()
	{
		InDegree = 0;
		OutDegree = 0;
		m_num = 0;
		m_Next = nullptr;
	}
};

struct ARC
{
	int m_EVex;
	struct ARC* m_Next;
	ARC()
	{
		m_EVex = 0;
		m_Next = nullptr;
	}
};

class AdjList
{
public:
	AdjList();
	void ShowAdj();
	void TopoSort();
private:
	struct VEX* m_Vex;
	int num;//节点数
	Stack<VEX> STACK;
};



int main()
{
	AdjList Graph;
	std::cout << "graph:" << std::endl;
	Graph.ShowAdj();
	std::cout << "topo:" << std::endl;
	Graph.TopoSort();
	return 0;
}

AdjList::AdjList()
{
	std::cout << "num:" << std::endl;
	std::cin >> num;
	m_Vex = new struct VEX[num]();
	for (int i = 0; i < num; i++)	
	{
		std::cout << "Node number " << i + 1 << ":" << std::endl;
		m_Vex[i].m_num = i + 1;
		std::cout << "ARC(input EndVex or end input by '-1'):" << std::endl;
		while(1)
		{
			struct ARC* Arc = new struct ARC();
			std::cin >> Arc->m_EVex;
			if (Arc->m_EVex == -1)	
			{
				delete Arc;
				break;
			}
			Arc->m_EVex -= 1; m_Vex[Arc->m_EVex].InDegree++;
			Arc->m_Next = m_Vex[i].m_Next; m_Vex[i].m_Next = Arc;
			m_Vex[i].OutDegree++;
		}

	}

}

void AdjList::ShowAdj()
{
	for (int i = 0; i < num; i++)
	{
		std::cout << "Node number :" << m_Vex[i].m_num << "Indegree:" << m_Vex[i].InDegree << std::endl;
		struct ARC* temp = m_Vex[i].m_Next;
		while (temp)
		{
			std::cout << m_Vex[i].m_num << "->" << temp->m_EVex + 1 << ' ' ;
			temp = temp->m_Next;
		}
		std::cout << std::endl;
	}
}

void AdjList::TopoSort()//使用栈的一种策略，优先深度，如果使用队列，那么优先广度
{
	struct VEX* Vex = new struct VEX [num]();
	for (int i = 0; i < num; i++)	Vex[i] = m_Vex[i];
	int* Visit = new int[num]();
	struct VEX Node;
	struct ARC* Temp = nullptr;
	for (int i = 0; i < num; i++)	
	{
		if (Vex[i].InDegree == 0)	
		{
			STACK.Push(Vex[i]);
			Visit[i] = 1;
		}
	}
	while (!STACK.IsEmpty())
	{
		Node = STACK.Pop();
		std::cout << Node.m_num << ' ';
		Temp = Node.m_Next;
		while (Temp)
		{
			Vex[Temp->m_EVex].InDegree--;
			Temp = Temp->m_Next;
		}
		for (int i = 0; i < num; i++)
		{
			if (Visit[i]==0 && Vex[i].InDegree == 0)
			{
				STACK.Push(Vex[i]);
				Visit[i] = 1;
			}
		}
	}
	delete[]Vex;
}
