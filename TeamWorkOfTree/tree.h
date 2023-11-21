#pragma once
#include<iostream>
#define MAX 10
#include"Stack.cpp"
class BiTree
{
public:

    BiTree* CreatTree();
    BiTree* CreatTree(int*,int );
    int MidTraversal(BiTree*);
    //void MidTraversal(BiTree* T); //test
private:
    BiTree* left;
    BiTree* right;
    int m_Data;
};



