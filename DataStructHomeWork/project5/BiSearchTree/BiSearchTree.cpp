#include <iostream>

class BiSearchTree
{
public:
    BiSearchTree() { m_Data = 0; left = nullptr; right = nullptr; BF = 0; }
    BiSearchTree* CreatTree();
    void HeadTraversal(BiSearchTree*);
    void MidTraversal(BiSearchTree*);
    void TailTraversal(BiSearchTree*);
    void Search(BiSearchTree*, int);
private:
    void DELETE(BiSearchTree*, BiSearchTree*);
    void CreatTreeHelper(BiSearchTree*, BiSearchTree*);
    int Deep(BiSearchTree*);
    BiSearchTree* GetMax(BiSearchTree*);
    int m_Data;
    BiSearchTree* left;
    BiSearchTree* right;
    int BF;//balance factor
};

int main()
{
    BiSearchTree* TREE = nullptr;
    TREE = TREE->CreatTree();
    TREE->MidTraversal(TREE);
    std::cout << std::endl;
    TREE->HeadTraversal(TREE);
    std::cout << std::endl;
    std::cout << "search num:" << std::endl;
    int Search; std::cin >> Search;
    TREE->Search(TREE, Search);
    TREE->MidTraversal(TREE);
    std::cout << std::endl;
}

BiSearchTree* BiSearchTree::CreatTree()
{
    std::cout << "Input num" << std::endl;
    int num;
    std::cin >> num; if (!num)    return nullptr;
    std::cout << "Input" << std::endl;
    BiSearchTree* ROOT = new BiSearchTree();
    std::cin >> ROOT->m_Data; ROOT->left = nullptr; ROOT->right = nullptr;
    for (int i = 1; i < num; i++)
    {
        BiSearchTree* TREE = new BiSearchTree();
        std::cin >> TREE->m_Data;
        TREE->left = nullptr; TREE->right = nullptr;
        CreatTreeHelper(ROOT, TREE);
    }
    return ROOT;
}



void BiSearchTree::CreatTreeHelper(BiSearchTree* T, BiSearchTree* NODE)
{
    while (1)
    {
        while (T->m_Data > NODE->m_Data && T->left)     T = T->left;
        while (T->m_Data < NODE->m_Data && T->right)    T = T->right;
        //仅有这三种情况时找到应该的位置
        //如果使用递归，插入后返回时会有一些情况会重复插入，也就是搜索二叉树有多个位置符合同一节点要求
        //使用这种方法，查找不需要回退
        if ((!T->left && !T->right) || (!T->left && T->right->m_Data > NODE->m_Data) || (!T->right && T->left->m_Data < NODE->m_Data))
            break;
    }
    if (T->m_Data > NODE->m_Data)
    {
        NODE->left = T->left;
        T->left = NODE;
    }
    else if (T->m_Data < NODE->m_Data)
    {
        NODE->right = T->right;
        T->right = NODE;
    }
}

void BiSearchTree::HeadTraversal(BiSearchTree* T)
{
    if (T != nullptr)
    {
        std::cout << T->m_Data << ' ';
        HeadTraversal(T->left);
        HeadTraversal(T->right);
    }

    return;
}

void BiSearchTree::MidTraversal(BiSearchTree* T)
{
    if (T != nullptr)
    {
        MidTraversal(T->left);
        std::cout << T->m_Data << ' ';
        MidTraversal(T->right);
    }

    return;
}

void BiSearchTree::TailTraversal(BiSearchTree* T)
{
    if (T != nullptr)
    {
        TailTraversal(T->left);
        TailTraversal(T->right);
        std::cout << T->m_Data << ' ';
    }

    return;
}

void BiSearchTree::Search(BiSearchTree* T, int SearchNum)
{
    int SearchTimes = 0;
    BiSearchTree* ROOT = T;
    while (T)
    {
        if (T->m_Data > SearchNum) T = T->left;
        else if (T->m_Data < SearchNum) T = T->right;
        else
        {
            std::cout << "Get it " << "SearchTimes:" << SearchTimes + 1 << std::endl;
            std::cout << "Will Delete it!" << std::endl;
            DELETE(ROOT, T);
            break;
        }
        SearchTimes++;
    }
    if (!T)
    {
        std::cout << "NO Such Number ";
        std::cout << "Will Add it!" << std::endl;
        BiSearchTree* TREE = new BiSearchTree();
        TREE->m_Data = SearchNum;
        TREE->left = nullptr; TREE->right = nullptr;
        CreatTreeHelper(ROOT, TREE);
    }
}

int BiSearchTree::Deep(BiSearchTree* T)
{
    int DOL = 0; int DOR = 0;
    if (T == nullptr)  return 0;
    DOL = Deep(T->left);
    DOR = Deep(T->right);
    if (DOL >= DOR) return ++DOL;
    else return ++DOR;
}

BiSearchTree* BiSearchTree::GetMax(BiSearchTree* T)
{
    while (T->right) T = T->right;
    return T;
}



void BiSearchTree::DELETE(BiSearchTree* T, BiSearchTree* NODE)
{
    BiSearchTree* Father = T;
    while (1)
    {
        while (T->m_Data > NODE->m_Data)
        {
            Father = T;
            T = T->left;
        }
        while (T->m_Data < NODE->m_Data)
        {
            Father = T;
            T = T->right;
        }
        if (T->m_Data == NODE->m_Data)
            break;
    }
    if (!T->left)
    {
        if (Father->left == T)  Father->left = T->right;
        else Father->right = T->right;
    }
    else if (!T->right)
    {
        if (Father->left == T)  Father->left = T->left;
        else Father->right = T->left;
    }
    else
    {

        BiSearchTree* Temp = GetMax(T->left);//找到T的左子树的最大节点
        Temp->right = T->right;//T的所有右子树都比Temp大直接连上
        //判断T是父节点的左孩子还是右孩子
        if (Father->left == T) Father->left = Temp;
        else if (Father->right == T) Father->right = Temp;
        if (T->left != Temp)//如果Temp不是T的左孩子，也就是T的左子树有右孩子
        {

            while (Temp->left)   Temp = Temp->left;//找到Temp最小的孩子
            //Temp最小的孩子也比T除Temp以外的所有节点大，因此直接连接到Temp最小的孩子的左孩子上
            Temp->left = T->left;
        }
    }
}
