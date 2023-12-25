#pragma once
#include"tree.h"
BiTree* BiTree::CreatTree()
{

    char Data;
    BiTree* Leaf = new BiTree;
    std::cin >> Data;
    if (Data == '#')
    {
        Leaf = nullptr;
    }
    else
    {
        Leaf->m_Data = Data;
        std::cout << Leaf->m_Data << std::endl;
        Leaf->left = CreatTree();
        Leaf->right = CreatTree();
    }
    return Leaf;
}


int BiTree::MidTraversal(BiTree* T)//�������
{
    int sum = 0;
    if (T->right != nullptr)
    {
        int Cfisrst;
        Cfisrst = MidTraversal(T->left);
        switch (T->m_Data)
        {
        case '+':
            sum = Cfisrst + MidTraversal(T->right); break;
        case '-':
            sum = Cfisrst - MidTraversal(T->right); break;
        case '*':
            sum = Cfisrst * MidTraversal(T->right); break;
        case '/':
            if (MidTraversal(T->right) == 0)//��0���
            {
                 std::cout << "divided by 0";exit(6);
            }
            sum = Cfisrst / MidTraversal(T->right); break;
        default:
            exit(2); break;
        }
    }
    else
    {
        return T->m_Data;
    }
    return sum;
}


//void BiTree::MidTraversal(BiTree* T)
//{
//    if (T != nullptr)
//    {
//        MidTraversal(T->left);
//        switch (T->m_Data)
//        {
//        case '+':
//        case '-':
//        case '*':
//        case '/':
//            std::cout << (char)T->m_Data << ' '; break;
//        default:
//            std::cout << T->m_Data << ' '; break;
//        }
//        //std::cout << sizeof(post) << std::endl;
//        MidTraversal(T->right);
//    }
//
//    return;
//}


//��ʼ�����Ҹ����������Ź�������������Ϊ������������ջΪ���ӣ�
//��һ������Ϊ�Һ��ӡ�
BiTree* BiTree::CreatTree(int* post, int flag)
{
	BiTree* LChild = nullptr;
	BiTree* RChild = nullptr;
	BiTree* Root = nullptr;
	Stack <BiTree*> STACK;

	bool f = false;
	for (int i = 0; i < flag; i++)  //������
	{                               //˼·������������ջ���������ţ���������ջ��������
		switch (post[i])            //�����������ٳ�ջ�������������������ɵ�����Ϊ��һ��
		{                           //������������ѭ��ֱ����������������
		case '+':                   //�������⣬���ж������ʱ����(1+1)*(1+1)+(1+1)�ͻ�����һ����������������������Ϊ��������
		case '-':                   //����������һ������ʱ����������ƴ����һ��          
		case '*':
		case '/':
		{
			Root = new BiTree;
			RChild = STACK.Pop();
			LChild = STACK.Pop();
			Root->m_Data = post[i];
			Root->left = LChild;
			Root->right = RChild;
			STACK.Push(Root);
			break;
		}
		default:
			Root = new BiTree;
			Root->m_Data = post[i];
			Root->left = nullptr; Root->right = nullptr;
			STACK.Push(Root);
		}
	}
	return Root;
}