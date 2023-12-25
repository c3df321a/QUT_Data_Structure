// Hash.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

enum state{EMPTY,DELETE,EXIST};

struct hash
{
    int Data;
    state m_state;
    hash() { Data = 0; m_state = EMPTY; }
};


class HASH
{
public:
    HASH();
    void Search(int);
private:
    int GetPrime(int);
    int num;
    int HashLength;
    hash* Hash;
    int HashSeed;
};

int main()
{
    HASH hash;
    std::cout << "search num:" << std::endl;
    int Search; std::cin >> Search;
    hash.Search(Search);
}

HASH::HASH()
{
    std::cout << "Input num" << std::endl;
    num;
    std::cin >> num;
    int* Input = new int[num]();
    std::cout << "Input" << std::endl;
    for (int i = 0; i < num; i++)   std::cin >> Input[i];

    HashSeed = GetPrime(num);
    std::cout << "HashSeed:" << HashSeed << ' ';
    HashLength = GetPrime(num / (0.7));
    std::cout  << "HashLength:" << HashLength << std::endl;
    Hash = new hash[HashLength]();

    int Post;
    for (int i = 0; i < num; i++)
    {
        Post = Input[i] % HashSeed;
        int flag = 1;
        while (Hash[Post].m_state == EXIST)
        {
            Post = (Input[i] + flag) % HashLength;
            flag++;
        }
        Hash[Post].Data = Input[i]; Hash[Post].m_state = EXIST;
    }
    for (int i = 0; i < HashLength; i++)
    {
        if (Hash[i].m_state == EXIST)  std::cout << Hash[i].Data << ' ';
        else std::cout << "NULL" << ' ';
    }
    std::cout << std::endl;
}

void HASH::Search(int SearchNum)
{
    int flag = 1;
    int Post = SearchNum % HashSeed;
    int times = 0;
    while (Hash[Post].m_state != EMPTY)
    {
        if (Hash[Post].m_state == EXIST && Hash[Post].Data == SearchNum)
        {   
            std::cout << "Get it" << "Post:" << Post << "times:" << times + 1 << std::endl;
            break;
        }
        Post = (SearchNum + flag) % HashLength;
        flag++;
        times++;
    }
    if(Hash[Post].m_state == EMPTY)  std::cout << "Null" <<std::endl;
}

int HASH::GetPrime(int num)
{
    while (num)
    {
        int i;
        for (i = 2; i < sqrt(num); i++)
        {
            if (num % i == 0)   break;
        }
        if (i >= sqrt(num))    break;
        num--;
    }
    return num;
}


