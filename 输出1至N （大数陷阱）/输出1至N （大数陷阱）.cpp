// 输出1至N （大数陷阱）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

void printNumber(char* numbers) {
	bool isBegin0 = true;
	int  lenth = strlen(numbers);
	for (int i = 0; i < lenth; ++i)
	{
		if (numbers[i] != '0' && isBegin0)
		{
			isBegin0 = false;
		}
		if (!isBegin0)
		{
			printf("%c",numbers[i]);
		}
	}
	printf("\t");
}




bool increaseNum(char* numbers) {
	bool isOverFlow = false;
	int  carry = 0;
	int lenth = strlen(numbers);
	for (int i = lenth - 1 ; i >= 0; i--)
	{
		int numberI = numbers[i] - '0' + carry;
		if (i == lenth-1)
		{
			numberI++;
		}
		if (numberI >= 10)
		{
			if (i == 0)
			{
				isOverFlow = true;
			}
			else
			{
				numberI -= 10;
				carry = 1;
				numbers[i] = '0'+ numberI ;
			}
		}
		else
		{
			numbers[i] = '0'+  numberI ;
			break;
		}
	}
	return isOverFlow;
}


void print0ToN(int n) {
	if (n <= 0)
	{
		return;
	}
	char* numbers = new char[n+1];
	memset(numbers,'0',n);
	numbers[n] = '\0';

	while (!increaseNum(numbers))
	{
		printNumber(numbers);
	}
	delete[] numbers;
}

int main()
{
	int n;
	cin >> n;

	print0ToN(n);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
