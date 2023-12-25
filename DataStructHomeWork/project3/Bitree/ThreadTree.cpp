//ThreadTree.cpp

#include"ThreadTree.h"
ThreadTree* ThreadTree::CreatTree()
{
    //ThreadTree::pre = nullptr;
    ClueData Data;
    ThreadTree* Leaf = new ThreadTree;
    std::cin >> Data.m_Data;
    if (Data.m_Data == '#')
    {
        Leaf = nullptr;
    }
    else
    {
        Leaf->m_Data = Data;
        //std::cout << Leaf->m_Data.m_Data << std::endl;
        Leaf->left = CreatTree();
        Leaf->right = CreatTree();
    }
    return Leaf;
}


void ThreadTree::MidTraversal(ThreadTree* T)
{
    if (T != nullptr)
    {
        MidTraversal(T->left);
        std::cout << T->m_Data.m_Data;
        MidTraversal(T->right);
    }

    return;
}

void ThreadTree::InThread(ThreadTree* T)
{
    if (T)
    {
        InThread(T->left);
        if (!T->left)
        {
            T->left = pre; T->m_Data.Lflag = true;
        }
        if (pre)
        {
            if(!pre->right)
            {
                pre->right = T; pre->m_Data.Rflag = true;
            }
        }
        pre = T;
        InThread(T->right);
    }

}

void ThreadTree::ShowThreadTree(ThreadTree* T)
{
    ThreadTree* temp = T;
    while (temp)
    {
        while (!temp->m_Data.Lflag) temp = temp->left;
        std::cout << temp->m_Data.m_Data;
        while(temp->m_Data.Rflag && temp)//右指针为true则直接寻找下一个线索
        {
            temp = temp->right;
            std::cout << temp->m_Data.m_Data;
        }
        //否则接着访问右侧节点
        if(temp)    temp = temp->right;
    }
}
