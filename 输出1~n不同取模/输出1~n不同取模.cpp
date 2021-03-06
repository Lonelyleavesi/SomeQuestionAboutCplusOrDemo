// 处理大数字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
using std::string;
using std::vector;


vector<string> fizzBuzz(int n) {
	vector<string> strs;
	if (n <= 0)
	{
		return strs;
	}
	int flag3 = 1;
	int flag5 = 1;
	string temp = "";
	for (int i = 1; i <= n; i++,flag3++,flag5++)
	{
		if (flag3 == 3 && flag5 == 5 )//(i%5 == 0 && i%3 == 0) //常数级优化
		{
			flag3 = 0;
			flag5 = 0;
			strs.push_back("FizzBuzz");
			continue;
		}
		if (flag3==3)//(i % 3 == 0)
		{
			flag3 = 0;
			strs.push_back("Fizz");
			continue;
		}
		if (flag5 == 5)//(i % 5 == 0)
		{
			flag5 = 0;
			strs.push_back("Buzz");
			continue;
		}

		strs.push_back(std::to_string(i));
	}
	return strs;
}

int main()
{
	vector<string>strs;
	strs = fizzBuzz(15);
	for (std::vector<string>::iterator it = strs.begin(); it != strs.end(); it++)
	{
		std::cout << *it << std::endl;
	}
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
