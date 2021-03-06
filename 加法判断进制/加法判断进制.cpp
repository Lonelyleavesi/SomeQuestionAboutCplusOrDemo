// 加法判断进制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目： 输入一个等式 等式中数字都在0~F 0123456789ABCDEF  num的长度0~5  进制最多20
//比如 ABCD + 211 = B000
//判断满足这个等式的 的进制 的个数以及多少进制
//输出 1  14 
//1 + 1 = 2
//16 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
////我开始没看懂这道题，以为很难，以为ABCD代表4个不同的数，后面才看懂
//时间不够了， 我说一下我的思路吧，
//我已经写出的代码 num1表示截取的 第一个加数， num2表示截取的第二个加数 result 表示结果
//判断当前出现的最大数，遍历str 的每一个char 可以用 isdigit判断是否为数字 如果是 就 char - '0';转化为int ，
//如果比当前的进制标识 carryN大，就令carry = 这个数+1 还要判断是否为ABCDEF 如果有A 至少为11进制
//如果有B至少为12进制 依次类推， 然后从当前进制到20进制进行遍历，遍历的同时 将num1 num2 num3转成int 判断是否成立
//比如14进制的  ABCD    13*pow(12,0) + 12*pow(12,1) + 11 * pow(12.2) + 10*pow(12.3)
//当然应该从num1 的 size（） 向前遍历， 同时用一个sum 储存num1所代表数的和
//转化完成了 就判断当前进制的成立情况 。可以用一个函数转化 f（num1,14） 吧num1 变成14进制的数
//f（num1,14） + f（num2,14） == f（result,14） 成立 就把14 push_back 一个vector中，
//最后输出vector 的大小 以及元素即可

#include "pch.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string num1;
	string num2;
	string str;
	cin >> str;
	int second = 0;
	int equelFlag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+')
		{
			num1 = str.substr(0,i);
			second = i + 1;
		}
		if (str[i] == '=')
		{
			num2 = str.substr(second,i-second );
			equelFlag = i + 1;
		}
	}
	string result = str.substr(equelFlag, str.size() - equelFlag);
	int carryN = 0;
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
