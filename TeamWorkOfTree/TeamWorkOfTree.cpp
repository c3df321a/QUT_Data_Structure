#include<iostream>
#include<CString>
#include"tree.h"
#include"Stack.cpp"



int OpJudge(const char& OP)
{
	switch (OP)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return -1;
	}
}

int trans(char* num)
{
	int sum = 0; int flag = 1;
	for (int i = strlen(num)-1; i >= 0; i--)
	{
		sum =sum+ (num[i] - 48) * flag; num[i] = '\0';
		flag = flag * 10;
	}
	return sum;
}

int change(std::string& input, int* post)
{
	for (int i = 0; i < input.size(); i++) { post[i] = '\0'; }//初始化
	char num[11]; for (int i = 0; i < 11; i++) { num[i] = '\0'; }
	int numflag = 0;//char to num
	bool mark = true;
	Stack <char> STACK;//栈
	int flag = 0;//后缀表达式记录
	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			//char to int
			num[numflag] = input[i];
			numflag++;
			if (numflag >= 11) exit(4);
			if (input[i + 1]>='0'&& input[i + 1] <= '9'){}
			else
			{
				numflag = 0;
				post[flag] = trans(num);
				flag++;
			}
		}
		//符号
		else
		{
			if (input[i] == '(')
			{
				STACK.Push(input[i]);
			}
			else if (input[i] == ')')
			{
				char temp;
				while (1)
				{
					temp = STACK.Pop();
					if (temp == '(')	break;
					post[flag] = temp;
					flag++;
				}
			}
			else
			{
				if (!STACK.IsEmpty()&&(OpJudge(STACK.GetTop()) >= OpJudge(input[i])))//下一个比上一个优先级高弹栈
				{
					char TopTemp = STACK.GetTop();
					if(TopTemp!='(')
					{
						while ((!STACK.IsEmpty() || OpJudge(STACK.GetTop()) >= OpJudge(TopTemp))&& OpJudge(STACK.GetTop()) != -1)
						{
							char temp = STACK.Pop();
							post[flag] = temp;
							flag++;
						}
					}
				}
				STACK.Push(input[i]);
			}
		}
	}
	//输出后缀和
	for (int i = 0; i < flag; i++)
	{
		switch (post[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			std::cout << (char)post[i]<<' '; break;
		default:
			std::cout << post[i] << ' '; break;
		}
		//std::cout << sizeof(post) << std::endl;
	}
	return flag;
}




int main()
{
	std::string input; 
	std::cout << "Input:" << std::endl;
	std::cin >> input;
	int* post = new int[input.size()];
	int flag = change(input, post);//返回数组长度，操作post
	std::cout << std::endl;
	BiTree* tree=nullptr;
	tree=tree->CreatTree(post,flag);//构建数
	std::cout << tree->MidTraversal(tree) << std::endl;//中序遍历求和
	//tree->MidTraversal(tree);
}