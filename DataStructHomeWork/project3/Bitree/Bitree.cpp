//BiTree.cpp

#include"BiTree.h"
#include"Queue.cpp"
#pragma once

template <class DataType>
BiTree<DataType>* BiTree<DataType>::CreatTree()
{

    DataType Data;
    BiTree* Leaf = new BiTree;
    std::cin >> Data;
    if (Data == '#')
    {
        Leaf = nullptr;
    }
    else
    {
        Leaf->m_Data = Data;
        //std::cout << Leaf->m_Data << std::endl;
        Leaf->left = CreatTree();
        Leaf->right = CreatTree();
    }
    return Leaf;
}

template <class DataType>
void BiTree<DataType>::HeadTraversal(BiTree* T)
{
    if (T != nullptr)
    {
        std::cout << T->m_Data;
        HeadTraversal(T->left);
        HeadTraversal(T->right);
    }

    return;
}
template <class DataType>
void BiTree<DataType>::MidTraversal(BiTree* T)
{
    if (T != nullptr)
    {
        MidTraversal(T->left);
        std::cout << T->m_Data;
        MidTraversal(T->right);
    }

    return;
}

template <class DataType>
void BiTree<DataType>::TailTraversal(BiTree* T)
{
    if (T != nullptr)
    {
        TailTraversal(T->left);
        TailTraversal(T->right);
        std::cout << T->m_Data;
    }

    return;
}


template <class DataType>
int BiTree<DataType>::Deep(BiTree<DataType>* T)
{
    int DOL = 0; int DOR = 0;
    if (T == nullptr)  return 0;
    DOL = Deep(T->left);
    DOR = Deep(T->right);
    if (DOL >= DOR) return ++DOL;
    else return ++DOR;
}



template<class DataType>
void BiTree<DataType>::LevelOrderTraversal(BiTree* T)
{
    Queue<BiTree*> QUEUE;
    BiTree* tempT = T;
    while(1)
    {
        if (tempT)  std::cout << tempT->m_Data;
        else return;
        if (tempT->left)    QUEUE.Push(tempT->left);
        if (tempT->right)   QUEUE.Push(tempT->right);
        if (!QUEUE.IsEmpty())    tempT = QUEUE.Pop();
        else break;
    }
    return;
}



template <class DataType>
Stack <DataType> ::Stack()//初始化
{
    m_Head = nullptr;
    m_Top = 0;
}

template <class DataType>
void Stack <DataType>::Push(BiTree<DataType>* Data)//入栈
{
    NODE<DataType>* node = new NODE<DataType>();
    node->m_Link = m_Head;
    m_Head = node;
    node->m_Data = Data;
    m_Top++;
}

template <class DataType>
BiTree<DataType>* Stack <DataType> ::Pop()//出栈
{
    if (m_Top != 0)
    {
        BiTree<DataType>* Data;
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
bool Stack <DataType> ::IsEmpty()//检查是否为空
{
    if (!m_Head)
        return true;
    else
        return false;
}


