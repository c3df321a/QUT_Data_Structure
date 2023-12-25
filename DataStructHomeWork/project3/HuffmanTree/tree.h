//tree.h
#pragma once
#include <iostream>

struct DataInfo
{
    char Data;//����
    char* string;//�������飬��¼����
    int weight;//Ȩֵ
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
    static int deep;//�����ȣ����ڵõ�������string�ĳ���
    static int i;//��������λ�ñ��
    static char* string;//�������飬��¼����
};
