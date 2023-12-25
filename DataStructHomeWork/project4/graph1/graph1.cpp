#include <iostream>
#include"PriorityQueue.cpp"
#include"Queue.cpp"
#define INF  2147483647;

struct Arc//储存边的信息
{
    int SVex;
    int EVex;
    int weight;
};


class AdjList
{
public:
    AdjList();
    void DFS(int);
    void BFS(int);
    void Krusal(int);
    void Prime(int);
private:
    void InitKrusal();//初始化
    void KrusalHelper(int);//辅助
    void PrimeHelper(int);//辅助
    void DFSHelper(int);//辅助
    void BFSHelper(int);//辅助
    int GetMin(int*);//Prime求目前最小的边
    int SetFind(int*,int);//并查集的寻根
    int Union(int*,int,int);//并查集合并

    static PriorityQueue<Arc> LPQ;//Krusal求最小
    int* Vex;//点的信息
    int** Arc;//邻接矩阵
    int num;//点的个数
    static int* Visit;//遍历的辅助数组
    static Queue<int> QUEUE;//BFS辅助队列
};

//静态变量初始化
PriorityQueue<Arc> AdjList::LPQ;
Queue<int> AdjList::QUEUE;
int* AdjList::Visit = nullptr;

int main()
{
    AdjList graph;
    std::cout << "DFS:" << std::endl;
    std::cout << "start:";
    int start = 0;
    std::cin >> start;
    graph.DFS(start);
    std::cout << std::endl;
    std::cout << "BFS:" << std::endl;
    std::cout << "start:";
    std::cin >> start;
    graph.BFS(start);
    std::cout << std::endl;
    std::cout << "Prime:" << std::endl;
    std::cout << "start:";
    std::cin >> start;
    graph.Prime(start);
    std::cout << "Krusal:" << std::endl;
    std::cout << "start:";
    std::cin >> start;
    graph.Krusal(start);
}

AdjList::AdjList()//初始化
{
    std::cout << "Vex num" << std::endl;
    std::cin >> num;
    Vex = new int[num]();
    Arc = new int* [num];
    for (int i = 0; i < num; i++)
    {
        Vex[i] = i + 1;
    }
    for (int i = 0; i < num; i++)
    {
        Arc[i] = new int[num]();
    }
    std::cout << "info:" << std::endl;
    for (int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            std::cin >> Arc[i][j];
        }
    }
    Visit = new int[num]();
}

void AdjList::DFS(int VEX)
{
    DFSHelper(VEX);
    for (int i = 0; i < num; i++)  Visit[i] = 0;
}

void AdjList::BFS(int VEX)
{
    BFSHelper(VEX);
    for (int i = 0; i < num; i++)  Visit[i] = 0;
}

void AdjList::Krusal(int VEX)
{
    InitKrusal();
    KrusalHelper(VEX-1);
}

void AdjList::Prime(int VEX)
{
    PrimeHelper(VEX-1);
}




void AdjList::InitKrusal()
{
    struct Arc m_Arc;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if(Arc[i][j] != 0)
            {
                m_Arc.SVex = i;
                m_Arc.EVex = j;
                m_Arc.weight = Arc[i][j];
                LPQ.Push(m_Arc,m_Arc.weight);
            }
        }
    }
}

void AdjList::KrusalHelper(int)
{
    int sum = 0;

    int flag = 0;

    struct Arc m_Arc;

    int* Set = new int[num]();
    for (int i = 0; i < num; i++) Set[i] = -1;//初始化集合数组
    while (!LPQ.IsEmpty() && flag<num-1)
    {
        m_Arc = LPQ.Pop();
        if (SetFind(Set, m_Arc.SVex) != SetFind(Set, m_Arc.EVex))//如果两者不属于同一集合，既二者不相连通
        {
            std::cout << m_Arc.SVex + 1 << "->" << m_Arc.EVex + 1 << "weight:" << m_Arc.weight << std::endl;
            sum += m_Arc.weight;
            Union(Set, SetFind(Set, m_Arc.SVex), SetFind(Set, m_Arc.EVex));
            flag++;
        }
    }
    std::cout << sum << std::endl;
}

void AdjList::PrimeHelper(int VEX)
{
    int* LowCast = new int[num]();
    int* from = new int[num]();

    int sum = 0;

    for (int i = 0; i < num; i++)//初始化辅助数组
    {
        if (Arc[VEX][i])    
        {
            LowCast[i] = Arc[VEX][i];
            from[i] = VEX;
        }
        else
        {
            LowCast[i] = INF;
            from[i] = VEX;
        }
    }
    LowCast[VEX] = 0;
    for (int i = 0; i < num - 1; i++)
    {
        int flag = GetMin(LowCast);//直接输出，在GetMin中进行了是否联通的判断
        std::cout << from[flag] + 1 << "->" << flag + 1 << "weight:" << LowCast[flag] << std::endl;
        sum += LowCast[flag];
        VEX = flag;
        for (int i = 0; i < num; i++) // 对辅助数组进行更改
        {  
            if (Arc[VEX][i] && Arc[VEX][i] < LowCast[i])
            {
                LowCast[i] = Arc[VEX][i];
                from[i] = VEX;
            }
        }
        LowCast[VEX] = 0;
    }
    std::cout << "total:" << sum << std::endl;
}

void AdjList::DFSHelper(int VEX)
{
    std::cout << VEX << ' ';
    Visit[VEX - 1] = 1;
    for (int i = 0; i < num; i++)
    {
        if (Arc[VEX - 1][i] && !Visit[i])
        {
            DFSHelper(Vex[i]);
        }
    }
}

void AdjList::BFSHelper(int VEX)
{
    if(!Visit[VEX-1])
    {
        std::cout << VEX << ' ';
        Visit[VEX - 1] = 1;
    }
    for (int i = 0; i < num; i++)
    {
        if (Arc[VEX - 1][i] && !Visit[i])
        {
            QUEUE.Push(Vex[i]);
        }
    }
    while (!QUEUE.IsEmpty())
    {
        BFSHelper(QUEUE.Pop());
    }
}

int AdjList::GetMin(int* LowCast)
{
    int flag = 0; int Min = INF;
    for (int i = 0; i < num; i++)
    {
        if (LowCast[i]!=0 && LowCast[i] < Min)//为0的点为已经连进了树中
        {
            Min = LowCast[i];
            flag = i;
        }
    }
    return flag;
}

int AdjList::SetFind(int* Set,int Node)
{
    int temp = Node;
    while (Set[temp] >= 0)
    {
        temp = Set[temp];
    }
    return temp;
}

int AdjList::Union(int* Set,int Root1,int Root2)
{
    if ((-Set[Root1]) > (-Set[Root2]))
    {
        Set[Root1] += Set[Root2];
        Set[Root2] = Root1;
        return Root1;
    }
    else
    {
        Set[Root2] += Set[Root1];
        Set[Root1] = Root2;
        return Root2;
    }
}
