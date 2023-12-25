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

    int Times = 0;
    int start = 0; int end = num - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (Input[mid] < Search)    start = mid;
        else if (Input[mid] > Search)  end = mid;
        else
        {
            std::cout << "Get it Times:" << Times + 1 << "POSITION:" << mid +1 << std::endl;
            break;
        }
        mid = (start + end) / 2;
    }
    if(start>=end)  std::cout << "no such num" << std::endl;
}
