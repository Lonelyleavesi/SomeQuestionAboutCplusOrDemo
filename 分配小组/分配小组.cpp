// 分配小组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//输入一个数n 表示接下来有n个人， 然后输入每个人想要加入组的人数， 
//最后判断能否组成组，能的话输出 组数，否则输出-1
//这道题开始没想到用map，开始想用的是二维vector 来存储，每次都要遍历有没有vector里面的值 和size 不相等来判断能否完成一个簇
//后来突然想到了map 思路就是对于 每个数放进对应的map 如果有就++ ，主要用了map在没有定义的时候 为0，所以对于第一个加入的ai 就变成了1，不会访问越界
//键表示想想要分得 多少组   值表示想要这个分组结果的人有几个
//当然是把想要分组相同的人放一起啦，  放一起后， 看看能不能除尽
//用到了map的遍历，map建立后 类似链表把它的每一个键值对链接了起来， 如果有不满足的就返回-1， 如果满足就计数，最后输出
#include "pch.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int pNum;
	cin >> pNum;
	int *pHope = new int[pNum];
	for (size_t i = 0; i < pNum; i++)
	{
		cin >> pHope[i];
	}
	map<int, int> tMap;
	for (size_t i = 0; i < pNum; i++)
	{
		tMap[pHope[i]] ++;
	}
	map<int, int>::iterator it;
	int sum = 0;
	int error = -1;
	for (it = tMap.begin(); it != tMap.end(); it ++) {
		if ((it->second)%(it->first) == 0)
		{
			sum += (it->second)/(it->first);
		}
		else{
			cout << error;
			return 0;
		}
	}
	cout << sum;
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
