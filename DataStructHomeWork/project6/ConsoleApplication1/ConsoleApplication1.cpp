
#include <iostream>
#include<time.h>
#define MAX 10

void InsertSort(int Input[])
{
	int IntTemp[MAX];
	for (int i = 0; i < MAX; i++)	IntTemp[i] = Input[i];

	for (int i = 1; i < MAX; i++)
	{
		int temp = IntTemp[i];//记录插入数
		int j = i - 1;//记录插入数的位置
		//比较的同时后移
		while (j>=0 && temp < IntTemp[j])//比较找到插入数应该在的位置
		{
			IntTemp[j + 1] = IntTemp[j];//将数组的数后移
			j--;
		}
		IntTemp[j + 1] = temp;//插入当前位置
		for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
		std::cout << std::endl;
	}
	std::cout << "After Insert Sort:";
	for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
	std::cout << std::endl;
}

void BinInsertSort(int Input[])
{
	int IntTemp[MAX];
	for (int i = 0; i < MAX; i++)	IntTemp[i] = Input[i];

	for (int i = 1; i < MAX; i++)
	{
		int temp = IntTemp[i];//记录插入数
		//先比较然后后移
		int begin = 0; int end = i - 1;
		int mid;
		while (begin <= end)
		{
			mid = (begin + end) / 2;
			if (IntTemp[mid] < temp)	begin = mid + 1;
			else end = mid - 1;
		}
		//////////
		for (int j = i - 1; j >= end + 1; j--)		IntTemp[j + 1] = IntTemp[j];
		IntTemp[end + 1] = temp;//插入当前位置
		for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
		std::cout << std::endl;
	}

	std::cout << "After BiInsert Sort:";
	for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
	std::cout << std::endl;
}

void QuickSortHelper(int Input[], int left, int right)
{
	int i = left; int j = right;
	if (left < right)
	{
		int temp = Input[left];
		while (i != j)
		{
			while (i < j && Input[j] >= temp)	j--;
			if (i < j)
			{
				Input[i] = Input[j];
				i++;
			}
			while (i < j && Input[i] <= temp)	i++;
			if (i < j)
			{
				Input[j] = Input[i];
				j--;
			}
		}
		Input[i] = temp;
		for (int i = 0; i < MAX; i++)	std::cout << Input[i] << ' ';
		std::cout << std::endl;
		QuickSortHelper(Input, left, i - 1);
		QuickSortHelper(Input, i + 1, right);
	}
}

void QuickSort(int Input[])
{
	int IntTemp[MAX];
	for (int i = 0; i < MAX; i++)	IntTemp[i] = Input[i];
	int left = 0; int right = MAX - 1;
	QuickSortHelper(IntTemp,left,right);

	std::cout << "After Quick Sort:";
	for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
	std::cout << std::endl;
}



void ShellSort(int Input[])
{

	int IntTemp[MAX];
	for (int i = 0; i < MAX; i++)	IntTemp[i] = Input[i];

	int ShellSeed = MAX / 2;
	int i = 0, j = 0;
	while (ShellSeed > 0)
	{
		for (i = ShellSeed; i < MAX; i++)
		{
			j = i - ShellSeed;
			while (j >= 0)
			{
				if (IntTemp[j] > IntTemp[j + ShellSeed])
				{
					int temp = IntTemp[j + ShellSeed];
					IntTemp[j + ShellSeed] = IntTemp[j];
					IntTemp[j] = temp;
				}
				j -= ShellSeed;
			}
		}
		for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
		std::cout << std::endl;
		ShellSeed /= 2;
	}
	std::cout << "After Shell Sort:";
	for (int i = 0; i < MAX; i++)	std::cout << IntTemp[i] << ' ';
	std::cout << std::endl;
}


void HeapSortHelper(int Input[], int aim, int Length)
{
	int temp = Input[aim];
	for (int i = aim * 2; i <= Length; i *= 2)
	{
		if (i < Length && Input[i] < Input[i + 1])	i++;
		if (temp >= Input[i])	break;
		else
		{
			Input[aim] = Input[i];
			aim = i;
		}
	}
	Input[aim] = temp;
}

void HeapSort(int Input[])
{
	int length = MAX;
	int IntTemp[MAX + 1] = {};
	for (int i = 0; i < MAX; i++)	IntTemp[i + 1] = Input[i];
	for (int i = MAX / 2; i > 0; i--)
	{
		HeapSortHelper(IntTemp, i, length);
		for (int i = 1; i < MAX + 1; i++)	std::cout << IntTemp[i] << ' ';
		std::cout << std::endl;
	}
	for (int i = length; i > 1; i--)
	{
		int temp = IntTemp[1];
		IntTemp[1] = IntTemp[i];
		IntTemp[i] = temp;
		HeapSortHelper(IntTemp, 1, i - 1);
		for (int i = 1; i < MAX + 1; i++)	std::cout << IntTemp[i] << ' ';
		std::cout << std::endl;
	}

	std::cout << "After Heap Sort:";
	for (int i = 1; i < MAX + 1; i++)	std::cout << IntTemp[i] << ' ';
	std::cout << std::endl;
}


int main()
{
	srand(time(0));
	int Input[MAX];
	for (int i = 0; i < MAX; i++)	Input[i] = rand() %101;
	std::cout << "Before Sort:";
	for (int i = 0; i < MAX; i++)	std::cout << Input[i] << ' ';
	std::cout << std::endl;
	InsertSort(Input);
	BinInsertSort(Input);
	QuickSort(Input);
	ShellSort(Input);
	HeapSort(Input);
}
