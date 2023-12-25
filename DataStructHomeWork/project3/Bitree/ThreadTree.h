//ThreadTree.h

#pragma once
#include <iostream>


struct ClueData
{
    char m_Data;
    bool Lflag = false;
    bool Rflag = false;
    ClueData() {}
};

class ThreadTree
{
public:

    ThreadTree* CreatTree();
    void MidTraversal(ThreadTree*);
    void InThread(ThreadTree*);
    void ShowThreadTree(ThreadTree*);
private:
    ThreadTree* left;
    ThreadTree* right;
    ClueData m_Data;
    static ThreadTree* pre;
};
