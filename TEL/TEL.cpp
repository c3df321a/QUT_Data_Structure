#include <iostream>

typedef struct DATA
{
    char Name[12];
    char Tel[12];
}DATA;

class List
{
public:
    List()
    {
        m_Data.Name[0] = {};
        m_Data.Tel[0] = {};
        m_next = nullptr;
        for (int i = 0; i < 'z' - 'a' + 1; i++)
        {
            INDEX[i] = nullptr;
        }
    }
    void CreatList(int);
    void ShowList();
    void ReverseList();
    bool BlurSeekList();
    void DeleteList();
    void ReviseList();
private:
    DATA m_Data;//电话簿数据
    List* m_next;
    //储存对应字母的的链表的地址
    List* INDEX['z' - 'a' + 2];//索引表，序号代表对应字母
};



void List::CreatList(int n)//创建链表初始化和增加数据
{
    List* temp ;
    List* Bef ;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = this;
        Bef = temp;
        std::cout << "输入第" << i + 1 << "个信息：" << std::endl;
        List* ListNode = new List();
        if (!ListNode)
        {
            std::cout << "1";
            exit;
        }
        std::cout << "姓名：" << std::endl;
        std::cin >> ListNode->m_Data.Name;
        std::cout << "电话：" << std::endl;
        std::cin >> ListNode->m_Data.Tel;
        //用于对输入数据按字母顺序进行排序与插入
        while (temp != nullptr && ListNode->m_Data.Name[0] > temp->m_Data.Name[0])
        {
            Bef = temp;
            temp = temp->m_next;
        }
        Bef->m_next = ListNode;
        ListNode->m_next = temp;
        INDEX[ListNode->m_Data.Name[0] -'a' - 1] = ListNode;
    }

}

void List::ShowList()//输出整个表格
{
    List* temp = m_next;
    while (temp)
    {
        std::cout << "姓名：" << temp->m_Data.Name << std::endl;
        std::cout << "电话：" << temp->m_Data.Tel << std::endl;
        temp = temp->m_next;
    }
    std::cout << std::endl;
}

void List::ReverseList()//链表逆置，现在没有用，为以后写入文件做准备
{
    List* temp = nullptr;
    List* phead = nullptr;
    List* head = this;
    while (temp != nullptr)
    {
        temp = head;
        head = head->m_next;
        temp->m_next = phead;
        phead = temp;

    }
}

bool List::BlurSeekList()//模糊查找
{
    bool result = false;
    char Data[13] = {};
    std::cout << "输入查找的姓名或电话号码" << std::endl;
    std::cin >> Data;
    List* temp = m_next;
    bool flag = false;
    for (int i = 0; i < 13; i++)
    {
        if (Data[0] >= 'a' && Data[0] <= 'z')
        {
            flag = true;
        }
    }
    if (!flag)
    {
        while (temp)
        {
            //使用c的函数strstr模糊查找，以后可以用kmp自己进行实现
            if (strstr(temp->m_Data.Tel, Data))
            {
                std::cout  << "姓名：" << temp->m_Data.Name << std::endl;
                std::cout << "电话：" << temp->m_Data.Tel << std::endl;
                result = true;
            }
            temp = temp->m_next;
            
        }
    }
    else
    {
        while (temp)
        {
            if (strstr(temp->m_Data.Name, Data))
            {
                std::cout << "姓名：" << temp->m_Data.Name << std::endl;
                std::cout << "电话：" << temp->m_Data.Tel << std::endl;
                result = true;
            }
            temp = temp->m_next;
        }
    }
    return result;
}

void List::DeleteList()
{
    char Data[13] = {};
    std::cout << "输入删除的姓名或电话号码" << std::endl;
    std::cin >> Data;
    List* temp = m_next;
    List* before= this;
    bool flag = false;
    for (int i = 0; i < 13; i++)//判断输入的是电话号码还是名字
    {
        if (Data[0] >= 'a' && Data[0] <= 'z')
        {
            flag = true;
        }
    }
    if (!flag)
    {
        while (temp)
        {
            if (strstr(temp->m_Data.Tel, Data))
            {
                before->m_next = temp->m_next;
                delete[]temp;
                return;
            }
            before = temp;
            temp = temp->m_next;
        }
        std::cout << "None" << std::endl;
    }
    else
    {
        while (temp)
        {
            if (strstr(temp->m_Data.Name, Data))
            {
                before->m_next = temp->m_next;
                delete[]temp;
                return;
            }
            before = temp;
            temp = temp->m_next;
        }
        std::cout << "None" << std::endl;
    }
    
}

void List::ReviseList()//修改
{
    char Data[13] = {};
    std::cout << "输入修改的姓名或电话号码" << std::endl;
    std::cin >> Data;
    bool flag = false;
    for (int i = 0; i < 13; i++)
    {
        if (Data[0] >= 'a' && Data[0] <= 'z')
        {
            flag = true;
        }
    }
    if (!flag)
    {
        List* temp = m_next;
        while (temp)
        {
            if (strstr(temp->m_Data.Tel, Data))
            {
                std::cout << "输入修改的姓名" << std::endl;
                std::cin >> temp->m_Data.Name;
                return;
            }
            temp = temp->m_next;

        }
        std::cout << "None" << std::endl;
    }
    else
    {
        //利用索引表99%的情况下可以优化大量时间
        List* start = nullptr;
        List* end = nullptr;
        start = INDEX[Data[0] -'a' - 1];
        char i = Data[0];
        while(!INDEX[i-'a']) { i++; }
        end = INDEX[i-'a'];
        if (!start)
        {
            std::cout << "None" << std::endl;
            return;
        }
        while (start!=end)
        {
            if (strstr(start->m_Data.Name, Data))
            {
                std::cout << "输入修改的电话" << std::endl;
                std::cin >> start->m_Data.Tel;
                return;
            }
            start = start->m_next;
        }
        std::cout << "none" << std::endl;
    }
}




int main()
{
    int num;
    std::cout << "输入初始化的电话簿信息数：" << std::endl;
    std::cin >> num;
    List* ListHead = new List();
    ListHead->CreatList(num);
    if(num)
    {
        ListHead->ShowList();
        std::cout << "初始化完成" << std::endl;
    }
    else { return 0; }
    //经典的消息分发
    while(num)
    {
        std::cout << "输入功能：" << std::endl;
        std::cout << "1:ShowList" << std::endl;
        std::cout << "2:SeekList" << std::endl;
        std::cout << "3:DeleteList" << std::endl;
        std::cout << "4:AddList" << std::endl;
        std::cout << "5:ReviseList" << std::endl;
        std::cout << "any other character:ShutDown" << std::endl;
        std::cin >> num;
        switch (num)
        {
        case 1:
            ListHead->ShowList(); break;
        case 2:
            if (!ListHead->BlurSeekList())
            {
                std::cout << "None" << std::endl;
            }
            break;
        case 3:
            ListHead->DeleteList(); 
            std::cout << "After Delete" << std::endl;
            ListHead->ShowList();

            break;
        case 4:
            ListHead->CreatList(1);
            std::cout << "After Add" << std::endl;
            ListHead->ShowList();
            break;
        case 5:
            ListHead->ReviseList();
            break;
        default:
            break;
        }
    }
    return 0;
}


