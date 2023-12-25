//mian
#include"ThreadTree.h"
#include"Bitree.cpp"
#include"Queue.cpp"
#include <iostream>

template <class DataType>
void Path(BiTree<DataType>* T)
{
    std::cout << "Value:" << std::endl;
    DataType Value; std::cin >> Value;
    Stack<DataType> STACK;
    while (T || !STACK.IsEmpty())
    {
        while(T && T->m_Data!=Value)
        {
            STACK.Push(T);
            T = T->left;
        }
        if (T && T->m_Data == Value) 
        {
            STACK.Push(T);
            break;
        }
        if (!STACK.IsEmpty())
        {
            T = STACK.Pop();
            
            T = T->right;
        }
    }
    Stack<DataType> Temp;
    while (!STACK.IsEmpty()) Temp.Push(STACK.Pop());
    while (!Temp.IsEmpty())std::cout << Temp.Pop()->m_Data;
}

ThreadTree* ThreadTree::pre = new ThreadTree;

int main()
{
    BiTree<char>* TheTree = new BiTree<char>;
    std::cout << "input the tree ended by '#'" << std::endl;
    TheTree = TheTree->CreatTree();
    std::cout << "HeadTraversal:" << std::endl;
    TheTree->HeadTraversal(TheTree);
    std::cout << std::endl;
    std::cout << "MidTraversal:" << std::endl;
    TheTree->MidTraversal(TheTree);
    std::cout << std::endl;
    std::cout << "TailTraversal:" << std::endl;
    TheTree->TailTraversal(TheTree);
    std::cout << std::endl;
    std::cout << "Deep:" << std::endl;
    std::cout << TheTree->Deep(TheTree) << std::endl;
    std::cout << "LevelOrderTraversal:" << std::endl;
    TheTree->LevelOrderTraversal(TheTree);
    std::cout << std::endl;
    std::cout << "Path:" << std::endl;
    Path<char>(TheTree);
    std::cout << std::endl;
    ThreadTree* THREADTREE = new ThreadTree;
    std::cout << "input the tree ended by '#'" << std::endl;
    THREADTREE = THREADTREE->CreatTree();
    std::cout << "MidTraversal:" << std::endl;
    THREADTREE->MidTraversal(THREADTREE);
    std::cout << std::endl;
    THREADTREE->InThread(THREADTREE);
    std::cout << "MidTraversal:(by InThread)" << std::endl;
    THREADTREE->ShowThreadTree(THREADTREE);

}
