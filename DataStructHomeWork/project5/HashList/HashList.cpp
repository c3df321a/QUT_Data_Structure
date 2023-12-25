// HashList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>



struct hash
{
    int Data;
    struct hash* Next;
    hash() { Data = 0; Next = nullptr; }
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
    std::cout << "HashSeed:" << HashSeed << ' ' << std::endl;
    HashLength = num;
    Hash = new struct hash[HashLength]();
    int Post;
    for (int i = 0; i < HashLength; i++)
    {
        Post = Input[i] % HashSeed;
        hash* temp = new hash();
        temp->Data = Input[i];
        temp->Next = Hash[Post].Next;
        Hash[Post].Next = temp;
    }
    hash* temp;
    for (int i = 0; i < HashLength; i++)
    {
        temp = Hash[i].Next;
        while (temp)
        {
            std::cout << temp->Data << ' ';
            temp = temp->Next;
        }
    }
    std::cout << std::endl;
}

void HASH::Search(int SearchNum)
{
    int times = 0;
    int Post = SearchNum % HashSeed;
    hash* temp = Hash[Post].Next;
    while (temp)
    {
        if (temp->Data == SearchNum)
        {
            std::cout << "Get it " << "times:" << times + 1 << std::endl;
            break;
        }
        temp = temp->Next;
        times++;
    }
    if (!temp)   std::cout << "NULL" << std::endl;
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