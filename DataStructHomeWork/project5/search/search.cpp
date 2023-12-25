
#include <iostream>

int main()
{
    std::cout << "Input num" << std::endl;
    int num;
    std::cin >> num;
    int* Input = new int[num]();
    std::cout << "Input" << std::endl;
    for (int i = 0; i < num; i++)   std::cin >> Input[i];
    std::cout << "search num:" << std::endl;
    int Search; std::cin >> Search;

    int i;
    for (i = 0; i < num; i++)
    {
        if (Input[i] == Search)    break;
    }
    if (i < num)   std::cout << "got it" << "SearchTimes:" << i + 1;
    else std::cout << "no such num";
}

