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


int BiTree::MidTraversal(BiTree* T)//遍历求和
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
            if (MidTraversal(T->right) == 0)//除0检查
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


//初始化左右根，遇到符号构造子树，符号为根，操作数出栈为左孩子，
//上一棵子树为右孩子。
BiTree* BiTree::CreatTree(int* post, int flag)
{
	BiTree* LChild = nullptr;
	BiTree* RChild = nullptr;
	BiTree* Root = nullptr;
	Stack <BiTree*> STACK;

	bool f = false;
	for (int i = 0; i < flag; i++)  //生成树
	{                               //思路：遇到数据入栈，遇到符号，操作数出栈做左子树
		switch (post[i])            //符号做根，再出栈操作数做右子树。生成的树作为下一个
		{                           //树的左子树。循环直到遍历晚整个数组
		case '+':                   //遇到另外，在有多个括号时例如(1+1)*(1+1)+(1+1)就会生成一棵子树进行上述操作，作为右子树，
		case '-':                   //并在遇到下一个符号时把左右子树拼接在一起。          
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