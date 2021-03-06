// 能否环绕（加油站问题）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
using std::vector;
using namespace std;
int moveHelp(vector<int>& gas, vector<int>& cost,int begin) {
	int currGas = gas[begin];
	int loc = begin+1;
	for (size_t i = 0; i < gas.size(); i++)
	{
		if (loc == gas.size())
		{
			loc = 0;
		}
		if (loc == 0)
		{
			currGas = currGas - cost[cost.size() - 1]+gas[loc];
		}
		else
		{
			currGas = currGas - cost[loc - 1] + gas[loc];
		}
		if (currGas < cost[loc])
		{
			return -1;
		}
		loc++;
	}
	return loc-1;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int beginLoc = 0;
	for (size_t i = 0; i < gas.size(); i++)
	{
		if (gas[i] >= cost[i])
		{
			int result = moveHelp(gas,cost,i);
			if (result != -1)
				return result;
		}
	}
	return -1;
}

int main()
{
	vector<int> gas = { 2 };
	vector<int> cost = { 2 };
	int result = canCompleteCircuit(gas, cost);
	cout << result;
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
