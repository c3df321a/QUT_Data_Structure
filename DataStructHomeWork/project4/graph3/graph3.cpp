#include <iostream>
#include"Stack.cpp"
#define INF  2147483647
#define VEXNUM 7

struct VEXNODE
{
    int m_num;
    std::string VexName;
    VEXNODE()
    {m_num = 0;}
};

struct Arc//储存边的信息
{
    int SVex;
    int EVex;
    int weight;
};


class AdjList
{
public:
    AdjList(int Map[][7],std::string*);
    void DFS(int);
    void BestPath(int, int);
private:
    void DFSHelper(int);//辅助

    void BestPathHelper(int, int);//Dijkstra

    int GetMin(int*);//求目前最小的边

    struct VEXNODE* Vex;//点的信息
    int** Arc;//邻接矩阵
    int num;//点的个数
    static int* Visit;//遍历的辅助数组
};

AdjList::AdjList(int Map[][7],std::string* MapNode)//初始化
{
    num = VEXNUM;
    Vex = new struct VEXNODE[num]();
    Arc = new int* [num];
    for (int i = 0; i < num; i++)
    {
        Vex[i].m_num = i;
        Vex[i].VexName = MapNode[i];
    }

    for (int i = 0; i < num; i++)
    {
        Arc[i] = new int[num]();
        Arc[i] = Map[i];
    }

    Visit = new int[num]();
}

void AdjList::DFS(int VEX)
{
    DFSHelper(VEX);
    for (int i = 0; i < num; i++)  Visit[i] = 0;
}

void AdjList::BestPath(int start, int end)
{
    BestPathHelper(start-1, end-1);
    for (int i = 0; i < num; i++)  Visit[i] = 0;
}



void AdjList::BestPathHelper(int start, int end)//from prime？
{
    int* LowCast = new int[num]();
    int* from = new int[num]();

    int VEX = Vex[start].m_num;//初始化

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
    LowCast[VEX] = 0;//路径长度
    from[VEX] = -1;//源自节点
    Visit[VEX] = 1;//是否被访问过


 
    int flag = 0;
    for (int i = 0; i < num - 1; i++)
    {
        flag = GetMin(LowCast);
        Visit[flag] = 1;
        for (int i = 0; i < num; i++)
        {
            if(i != start)//起始节点跳过
            {
                if (Arc[flag][i] != 0)
                {
                    int temp = LowCast[flag] + Arc[flag][i];//如果新路径权值小，则改变来源节点与最小路径
                    if (temp < LowCast[i])
                    {
                        LowCast[i] = temp;
                        from[i] = flag;
                    }
                }
            }
        }




        VEX = flag;
    }

    Stack<int> STACK;
    int temp = end;
    while (temp != -1)
    {
        STACK.Push(temp);
        temp = from[temp];
    }
    while (1)
    {
        std::cout << Vex[STACK.Pop()].VexName;
        if (!STACK.IsEmpty())  std::cout << "->";
        else break;
    }
    std::cout << std::endl;
    std::cout << "total:" << LowCast[end] << std::endl;
}

void AdjList::DFSHelper(int VEX)
{
    std::cout << VEX << ' ';
    Visit[VEX - 1] = 1;
    for (int i = 0; i < num; i++)
    {
        if (Arc[VEX - 1][i] && !Visit[i])
        {
            DFSHelper(Vex[i].m_num);
        }
    }
}

int AdjList::GetMin(int* LowCast)
{
    int flag = 0; int Min = INF;
    for (int i = 0; i < num; i++)
    {
        if (LowCast[i] != 0 && Visit[i]!=1 && LowCast[i] < Min)//from prrime add Visit[i]!=1
        {
            Min = LowCast[i];
            flag = i;
        }
    }
    return flag;
}

int* AdjList::Visit = nullptr;

int main()
{
    int Map[7][7] = {
        {0,2,3,0,0,0,0},
        {2,0,2,4,0,0,0},
        {3,2,0,0,1,0,0},
        {0,4,0,0,3,0,4},
        {0,0,1,3,0,4,0},
        {0,0,0,0,4,0,6},
        {0,0,0,4,0,6,0}
    };
    std::string MapNode[7] = {
        "北二宿舍",
        "北区食堂",
        "主教学楼",
        "二教",
        "图书馆",
        "信控楼",
        "南二门"
    };
    std::cout << "1：北二宿舍" << std::endl;
    std::cout << "2：北区食堂" << std::endl;
    std::cout << "3：主教学楼" << std::endl;
    std::cout << "4：二教" << std::endl;
    std::cout << "5：图书馆" << std::endl;
    std::cout << "6：信控楼" << std::endl;
    std::cout << "7：南二门" << std::endl;
    int start, end;
    std::cout << "input your start" << std::endl;
    std::cin >> start; 
    std::cout << "input your end:" << std::endl;
    std::cin >> end;
    AdjList Graph(Map,MapNode);
    Graph.BestPath(start, end);
}

