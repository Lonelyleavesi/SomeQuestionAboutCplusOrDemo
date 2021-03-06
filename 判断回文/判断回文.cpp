// 判断回文.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using std::string;

bool isPalindrome(string s) {
	if (s.empty())
	{
		return true;
	}
	int flag = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]) || isdigit(s[i])){
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		return true;
	}
	int l = 0;
	int r = s.size() - 1;
	while (l <= r)
	{

		while (!isalpha(s[l]) && !isdigit(s[l]))
		{
			if (l == r)
			{
				break;
			}
			l++;
			if (l > r)
			{
				return false;
			}
		}
		while (!isalpha(s[r]) && !isdigit(s[r]))
		{
			if (l == r)
			{
				break;
			}
			r--;
			if (l > r)
			{
				return false;
			}
		}
		if (isupper(s[l]))
		{
			s[l] = s[l] + 'a' - 'A';
		}
		if (isupper(s[r]))
		{
			s[r] = s[r] + 'a' - 'A';
		}
		if (l <= r && s[l] != s[r])
		{
			return false;
		}
		l++;
		r--;
	}
	return true;
}

int main()
{
	string str = "a a";
    std::cout << isPalindrome(str);
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
