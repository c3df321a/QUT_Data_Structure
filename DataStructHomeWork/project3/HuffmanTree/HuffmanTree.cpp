//main
#include <iostream>
#include"PriorityQueue.h"
#include"tree.h"

char* BiTree::string = nullptr;
int BiTree::deep = 0;
int BiTree::i = 1;
DataInfo BiTree::DATA[27] = {};

void calculate(std::string& input,char arr[])//可以拓展用256个字节大小的数组存放整个ASCII码表，目前先写出对于字母的处理
{
    
    std::cout << "input:" << std::endl;
    std::cin >> input;
    //std::cout << input << std::endl;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')         arr[input[i] - 'a']++;             
    }
}

int main()
{
    std::string input;
    BiTree* Huffmantree = new BiTree;
    char arr[27];
    for (int i = 0; i < 26; i++)   arr[i] = '\0';
    calculate(input,arr);
    Huffmantree = Huffmantree->CreatTree(arr);
    std::cout << "Tree:" << std::endl;
    std::cout << "HeadTraversal:" << std::endl;
    Huffmantree->HeadTraversal(Huffmantree);//先序和后续遍历来确定这一颗树
    std::cout << std::endl;
    std::cout << "MidTraversal:" << std::endl;
    Huffmantree->MidTraversal(Huffmantree);
    std::cout << std::endl;

    Huffmantree->HFM(Huffmantree);
    std::cout << "code:" << std::endl;
    Huffmantree->MidTraversal(Huffmantree);
    std::cout << std::endl;
    std::cout << "coded input:" << std::endl;
    for (int i = 0; i < input.size(); i++) 
    {
        std::cout << BiTree::DATA[input[i] - 'a'].string << ' ';
    }

}
