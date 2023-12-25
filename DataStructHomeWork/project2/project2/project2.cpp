//main
#include<iostream>
#include<string>
#include"Stack.cpp"//模板类不能用.h
#include"Line.cpp"

struct Data			//车牌号和时间
{
	std::string License;
	clock_t start;
};

int main()
{
	int MaxPark;//停车场最大停车数
	std::cout << "MaxPark:" << std::endl;
	std::cin >> MaxPark;

	int CarNum;//汽车数目
	std::cout << "car num:" << std::endl;
	std::cin >> CarNum;


	Stack<Data> STACK;Line<Data> LINE;//初始化，
	if (CarNum > MaxPark)
	{
		for (int i = 0; i < MaxPark; i++)
		{
			Data DATA;
			std::cout << "in park License:";
			std::cin >> DATA.License;
			DATA.start = clock();
			STACK.Push(DATA);
		}
		for (int i = MaxPark; i < CarNum; i++)
		{
			Data DATA;
			std::cout << "in line License:";
			std::cin >> DATA.License;
			DATA.start = clock();
			LINE.Push(DATA);
		}
	}
	else
	{
		for (int i = 0; i < CarNum; i++)
		{
			Data DATA;
			std::cout << "in park License:";
			std::cin >> DATA.License;
			DATA.start = clock();
			STACK.Push(DATA);
		}
	}


	//出去的车辆牌照
	std::string OutLicense;
	std::cout << "input license" << std::endl;
	std::cin >> OutLicense;

	Stack<Data> Stemp; Line<Data> Ltemp;
	Data DST; Data DLT;//data stack temp  data line temp

	bool Lflag = false;//判断是否在队列里
	bool Sflag = false;//判断是否在停车场里

	if (CarNum > MaxPark)//是否在队列里
	{
		while(!LINE.IsEmpty())
		{
			DLT = LINE.Pop();
			if (DLT.License == OutLicense)
			{
				std::cout << "in line" << std::endl;
				Lflag = true;//在队列里
				break;
			}
			Ltemp.Push(DLT);
		}
		while (!Ltemp.IsEmpty())	LINE.Push(Ltemp.Pop());
	}



	while (!STACK.IsEmpty() && !Lflag)//是否在停车场里
	{
		DST = STACK.Pop();
		if (DST.License == OutLicense)
		{
			std::cout << "in park" << std::endl;
			clock_t end = clock();//输出停车时间
			std::cout << "park time:" << (double)((end - DST.start) / CLOCKS_PER_SEC) << std::endl;
			Sflag = true;//在停车场里
			break;
		}
		Stemp.Push(DST);
	}



	if (STACK.IsEmpty() && !Sflag)//如果也不在停车场里
	{
		std::cout << "no such car" << std::endl;
		while (!Stemp.IsEmpty())		STACK.Push(Stemp.Pop());
	}
	else
	{
		if(CarNum>MaxPark && !LINE.IsEmpty())//队列里的第一辆车进入停车场
		{
			DLT = LINE.Pop();
			DLT.start = clock();
			STACK.Push(DLT);
			std::cout << "First Car In Line Has Got In" << std::endl;
			while (!Stemp.IsEmpty())		STACK.Push(Stemp.Pop());
		}
		else
		{
			std::cout << "No More Car Need Get In" << std::endl;
		}
	}

	return 0;
}