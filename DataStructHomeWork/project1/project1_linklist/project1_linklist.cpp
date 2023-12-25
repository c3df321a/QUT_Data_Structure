#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class LinkList
{
public:
	Node* Head;
public:
	LinkList();
	~LinkList();
	void Init();
	void Find();
	void Change();
	void Delete();
	void Print();
	void Menu();
};
LinkList::LinkList() { Head = NULL; }
LinkList::~LinkList() {
	Node* Temp = NULL;
	while (Head != NULL)
	{
		Temp = Head;
		Head = Head->next;
		delete Temp;
	}
}
void LinkList::Init()
{
	Head = new(Node);
	Head->next = NULL;
	Node* Head_temp = Head;
	cout << "请输入你要初始化的车厢数目" << endl;
	int n;
	cin >> n;
	int M;

	for (int i = 1; i <= n; i++)
	{
		cout << "请输入第" << i << "节车厢运载货物重量" << endl;
		cin >> M;
		Node* node = new(Node);
		node->data = M;
		node->next = NULL;
		Head_temp->next = node;
		Head_temp = node;
	}
}
void LinkList::Find()
{
	cout << "请输入车厢序号：";
	int i;
	cin >> i;
	cout << endl;
	Node* Head_temp = Head->next;
	int count = 1;
	while (Head_temp != NULL)
	{
		if (count++ == i)
			cout << "weight:" << Head_temp->data << endl;
		Head_temp = Head_temp->next;
	}
}
void LinkList::Change()
{
	cout << "请输入车厢序号：";
	int i;
	cin >> i;
	cout << "   请输入要修改后的值:";
	int data;
	cin >> data;
	cout << endl;
	Node* Head_temp = Head->next;
	int count = 1;
	while (Head_temp != NULL)
	{
		if (count++ == i)
		{
			cout << "修改前的值：" << Head_temp->data << endl;;
			Head_temp->data = data;
			cout << "修改后的值：" << Head_temp->data << endl;
		}
		Head_temp = Head_temp->next;
	}
}
void LinkList::Delete()
{
	cout << "请输入要删除车厢序号：";
	int i;
	cin >> i;
	cout << endl;
	Node* Head_temp = Head->next;
	Node* Head_Temp = Head;
	int count = 1;
	while (Head_temp != NULL)
	{
		if (count++ == i)
		{
			Head_Temp->next = Head_temp->next;
			delete Head_temp;
			break;
		}
		Head_Temp = Head_temp;
		Head_temp = Head_temp->next;

	}
	Print();
}
void LinkList::Print()
{
	Node* Head_temp = Head->next;
	int i = 1;
	while (Head_temp != NULL)
	{
		cout << "第" << i++ << "节车厢的重量是" << Head_temp->data << endl;
		Head_temp = Head_temp->next;

	}
}
void LinkList::Menu()
{
	cout << "1.find" << endl;
	cout << "2.revise" << endl;
	cout << "3.delete" << endl;
	cout << "4.output" << endl;
}
int main()
{
	LinkList m_list;
	int select;
	m_list.Init();
	while (1)   //利用while循环，实现程序的一直运行
	{
		m_list.Menu();
		cin >> select;
		switch (select)   //运用switch分支
		{
		case 1:
		{
			m_list.Find();
			break;
		}
		case 2:
		{
			m_list.Change();
			break;
		}
		case 3:
		{
			m_list.Delete();
			break;
		}
		case 4:
		{
			m_list.Print();
			break;
		}
		default:
			cout << "输入有误！" << endl;
		}
		system("pause");
	}
}
