//tree.h
#pragma once
#include <iostream>

struct DataInfo
{
    char Data;//数据
    char* string;//编码数组，记录编码
    int weight;//权值
    DataInfo() 
    {
        Data = '\0'; 
        string = nullptr;
        weight = -1;
    }
};

class BiTree
{
public:
    BiTree() { left = nullptr; right = nullptr;}
    BiTree* CreatTree(char*);
    void Creatnode(char,int);
    void HeadTraversal(BiTree*);
    void MidTraversal(BiTree*);
    void HFM(BiTree*);
    int Deep(BiTree*);
    static DataInfo DATA[27];
private:
    DataInfo m_Data;
    BiTree* left;
    BiTree* right;
    static int deep;//书的深度，用于得到树编码string的长度
    static int i;//辅助数组位置标记
    static char* string;//辅助数组，记录编码
};
