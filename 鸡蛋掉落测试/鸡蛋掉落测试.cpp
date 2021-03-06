// 鸡蛋掉落测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int superEggDrop(int K, int N) {
	
	int  **numdrops = new int* [K + 1];
	for (int i = 0; i < K+1; i++)
	{
		numdrops[i] = new int[N + 1];
	}
	for (int i = 0; i<	N+1; i ++) {
		numdrops[0][i] = 0;
		numdrops[1][i] = i;
	}
	for (int i = 0; i < K+1; i++) {
		numdrops[i][0] = 0; // zero floor
	}
	for (int  i = 2; i < K+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			int minimum = 9999999999999;
			for (int x = 1; x < j+1; x++)
			{
				minimum = min(minimum, (1 + max(numdrops[i][j - x], numdrops[i - 1][ x - 1])));
			}
			numdrops[i][j] = minimum;
		}
	}
	for (int i = 0; i < K + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			cout<<numdrops[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	return numdrops[K][N];
}

int main()
{
    std::cout <<superEggDrop(4,20);  //4个鸡蛋在20层中找要碎蛋的层
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
