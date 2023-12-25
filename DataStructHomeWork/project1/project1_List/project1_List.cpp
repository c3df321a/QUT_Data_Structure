

#include <iostream>
#include <algorithm>
using namespace std;


class List
{
public:
	List(int);
	void List_Print();
	void List_Delete();
	void change();
	void Sort();
	int GetLenth();
	int* m_head;
private:
	int m_lenth;
};

void Combin();



List::List(int lenth = 0)
{
	int flag = 1;
	if (lenth == 0) 
	{
		cout << "LIST LENTH:" << endl;
		cin >> lenth;
		flag = 0;
	}	
	m_lenth = lenth;
	m_head = new int[lenth + 1];
	if (!m_head)	exit(1);
	for (int i = 0; i < lenth + 1; i++)	m_head[i] = 0;
	if(flag==0)
	{
		cout << "LIST:" << endl;
		for (int i = 0; i < lenth; i++)	cin >> m_head[i];
	}

}

void List::List_Print()
{
	for (int i = 0; i < m_lenth; i++)	cout << m_head[i];
	cout << endl;
}

void List::List_Delete()
{
	int num; int flag;
	cout << "num:";
	cin >> num;
	cout << endl << "tpye Loc:0,Data:1";
	cin >> flag;
	int temp = -1;
	switch (flag)
	{
	case 0:
		for (int i = --num; i < m_lenth; i++)	m_head[i] = m_head[i + 1];
		m_lenth--;
		break;
	case 1:
		for (int i = 0; i < m_lenth; i++)
		{
			if (m_head[i] == num)
			{
				temp = i;
				break;
			}
		}
		if (temp != -1)
			for (int i = temp; i < m_lenth; i++)	m_head[i] = m_head[i + 1];
		else
			cout << "wrong input" << endl;
		m_lenth--;
		break;
	default:
		cout << "wrong input" << endl; return;
	}
}

void List::change()
{
	int Hflag = 0, Bflag = m_lenth; int temp = 0;
	bool HBOOL = false; bool BBOOL = false;
	while(Hflag<Bflag)
	{
		if (HBOOL && BBOOL)
		{
			temp = m_head[Hflag];
			m_head[Hflag] = m_head[Bflag];
			m_head[Bflag] = temp;
			Hflag++; Bflag--;
		}
		if (m_head[Hflag] % 2 == 1)	Hflag++;
		else	HBOOL = true;
		if (m_head[Bflag] % 2 == 0)	Bflag--;
		else	BBOOL = true;
	}
}

void List::Sort()
{
	sort(m_head, m_head + m_lenth);
}

int List::GetLenth()
{
	return m_lenth;
}

void Combin()
{
	List LIST1;
	List LIST2;
	List FINLIST(LIST1.GetLenth() + LIST2.GetLenth());
	int flag = 0, L1flag = 0, L2flag = 0;
	LIST1.Sort(); LIST2.Sort();
	while (L1flag < LIST1.GetLenth() && L2flag < LIST2.GetLenth())
	{
		if (LIST1.m_head[L1flag] <= LIST2.m_head[L2flag])
		{
			FINLIST.m_head[flag] = LIST1.m_head[L1flag];
			flag++; L1flag++;
		}
		else
		{
			FINLIST.m_head[flag] = LIST2.m_head[L2flag];
			flag++; L2flag++;
		}
	}
	while (L1flag < LIST1.GetLenth())
	{
		FINLIST.m_head[flag] = LIST1.m_head[L1flag];
		flag++; L1flag++;
	}
	while (L2flag < LIST2.GetLenth())
	{
		FINLIST.m_head[flag] = LIST2.m_head[L2flag];
		flag++; L2flag++;
	}
	FINLIST.List_Print();
}

void Menu()   //菜单栏
{
	cout << "1.print" << endl;
	cout << "2.delete" << endl;
	cout << "3.odd_even change" << endl;
	cout << "4.sort" << endl;
	cout << "5.combin" << endl;
	cout << "请输入你要执行的操作！" << endl;
}



int main()
{
	List LIST;
	int select;
	while (1)   //利用while循环，实现程序的一直运行
	{
		Menu();
		cin >> select;
		switch (select)   //运用switch分支
		{
		case 1:
		{
			LIST.List_Print();
			break;
		}
		case 2:
		{
			LIST.List_Delete();
			LIST.List_Print();
			break;
		}
		case 3:
		{
			LIST.change();
			LIST.List_Print();
			break;
		}
		case 4:
		{
			LIST.Sort();
			LIST.List_Print();
			break;
		}
		case 5:
		{
			Combin();
			break;
		}
		default:
			cout << "输入有误！" << endl;
		}
		system("pause");
	}
}

