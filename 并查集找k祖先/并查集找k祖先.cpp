// 并查集找k祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个并查集 查找 一个人p 和他同一k辈祖先的  兄弟有几个，
//我当时的思路是建立一个n*n的二维矩阵， a[p-1][k-1] 则为第p个人 的k祖先是谁，就找相同的
//可能更好的思路是用find函数， 我当时觉得如果要存差k代祖先需要用一个静态变量不好处理，现在觉得可以通过全局变量或者当做参数来解决这个问题


#include "pch.h"
#include <bits/stdc++.h>
using namespace std;
void creatPTree(int **pTree,int bcj[],int pNum) {
	for (size_t i = 0; i < pNum; i++)
	{
		pTree[i] = new int[pNum];
		for (size_t j = 0; j < pNum; j++)
		{
			pTree[i][j] = 0;
		}
	}
	for (int i = 0; i < pNum; i++)
	{
		if (bcj[i] != 0)
		{
			int gen = 0;
			int seek = i;
			while (bcj[seek] != 0)
			{
				pTree[i][gen] = bcj[seek];
				seek = bcj[seek] - 1;
				gen++;
			}
		}
	}
	/*for (size_t i = 0; i < pNum; i++)
	{
		for (size_t j = 0; j < pNum; j++)
		{
			cout << pTree[i][j] << " ";
		}
		cout << endl;
	}*/
}

int findKgen(int **pTree,int p, int k, int Num) {
	int count = 0;
	int kFather = pTree[p - 1][k - 1];
	for (size_t i = 0; i < Num; i++)
	{
		if ( i != p-1 && pTree[i][k-1] == kFather && pTree[i][k - 1] != 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int pNum = 10;
	cin >> pNum;
	int *bcj = new int[pNum];
	for (size_t i = 0; i < pNum; i++)
	{
		cin >> bcj[i];
	}
	int **pTree = new int*[pNum];
	creatPTree(pTree,bcj,pNum);
	int m = 10;
	cin >> m;
	int p, k;
	int *ans = new int[m];
	for (size_t i = 0; i < m; i++)
	{
		cin >> p >> k;
		ans[i] = findKgen(pTree, p, k, pNum);
	}
	cout << ans[0];
	for (size_t i = 1; i < m; i++)
	{
		cout << " " << ans[i];
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
