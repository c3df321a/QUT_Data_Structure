//treee.cpp
#pragma once
#include"tree.h"
#include"PriorityQueue.cpp"
BiTree* BiTree::CreatTree(char* arr)
{
	PriorityQueue<BiTree*> PriorityQueue;
	for (int i = 0; i < 26; i++)
	{
		if(arr[i])
		{
			BiTree* node = new BiTree;
			node->Creatnode((char)(i + 'a'),arr[i]);
			PriorityQueue.Push(node, arr[i]);
		}
	}
	BiTree* LChild = nullptr;
	BiTree* RChild = nullptr;
	while (!PriorityQueue.IsEmpty())
	{
		LChild = PriorityQueue.Pop();
		if (!PriorityQueue.IsEmpty())
		{
			RChild = PriorityQueue.Pop();
			BiTree* Root = new BiTree;
			Root->left = LChild; Root->right = RChild;
			Root->m_Data.Data = '\0'; //不存储数据
			Root->m_Data.weight = LChild->m_Data.weight + RChild->m_Data.weight;//权值相加
			PriorityQueue.Push(Root, Root->m_Data.weight);
		}
		else break;
	}


	deep = LChild->Deep(LChild);//符号数组长度

	string = new char[deep + 2]; string[0] = '0';//第一个永远是零
	for (int i = 1; i <= deep; i++)	string[i] = '\0';//初始化

	return LChild;


}

void BiTree::Creatnode(char Data,int weight)
{
	left = nullptr, right = nullptr;
	m_Data.Data = Data;
	m_Data.weight = weight;
}


void BiTree::HeadTraversal(BiTree* T)
{
	if (T != nullptr)
	{
		if (T->m_Data.Data)
		{
			std::cout << T->m_Data.Data<<' ';
		}
		else
		{
			std::cout << T->m_Data.weight<<' ';
		}
		HeadTraversal(T->left);
		HeadTraversal(T->right);
	}

	return;
}

void BiTree::MidTraversal(BiTree* T)
{
	if (T != nullptr)
	{
		MidTraversal(T->left);
		if(T->m_Data.Data)
		{
			std::cout << T->m_Data.Data<<' ';
		}
		else if(!T->m_Data.Data && !T->m_Data.string)
		{
			std::cout << T->m_Data.weight<<' ';
		}
		if(!T->m_Data.string)
		{
			T->m_Data.string = new char[deep+2];
			for (int i = 0; i <= deep; i++)	T->m_Data.string[i] = '\0';
		}
		else
		{
			if (T->m_Data.Data)	DATA[T->m_Data.Data - 'a'] = T->m_Data;
			std::cout << std::endl;
			for (int i = 0; i < strlen(T->m_Data.string); i++)
			{
				std::cout << T->m_Data.string[i];
			}
		}
		MidTraversal(T->right);
	}

	return;
}



int BiTree::Deep(BiTree* T)
{
	int DOL = 0; int DOR = 0;
	if (T == nullptr)  return 0;
	DOL = Deep(T->left);
	DOR = Deep(T->right);
	if (DOL >= DOR) return ++DOL;
	else return ++DOR;
}



//思路：递归遍历，来源左子树标零，来源右子树标一
void BiTree::HFM(BiTree* T)//左0右1
{
		if (T)
		{
			string[i] = '0';
			i++;
			HFM(T->left);
			string[i] = '1';
			i++;
			HFM(T->right);
			if (T->m_Data.Data)	for (int i = 0; i < strlen(string); i++)	T->m_Data.string[i] = string[i];
		}
		
		string[i-1] = '\0'; 
		//std::cout << string << std::endl;
		i--;
}



