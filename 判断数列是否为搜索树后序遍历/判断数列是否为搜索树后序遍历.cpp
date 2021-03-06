// 判断数列是否为搜索树后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isBST(int a[ ], int lenth){
	if (a == nullptr || lenth <= 0)
	{
		return false;
	}
	int root = a[lenth - 1];   //BST树的根
	int i = 0;
	for (; i < lenth-1; i++){
		if (a[i] > root)   //找到 比root大的数的时候 表示到右子树了
		{
			break;
		}
	}
	int j = i;
	for (; j < lenth-1; ++j)
	{
		if (a[j] < root)  //如果右子树有比root小的 代表不为BST
		{
			return false;
		}
	}
	bool left = true;
	if(i>0)
		left = isBST(a, i);

	bool right = true;
	if(i<lenth - 1)
	right = isBST(a + i, lenth-i -1);

	return left & right;
}

int main()
{
	int a[] = {5,7,6,9,11,10,8};
	bool result = isBST(a, 7);
    std::cout << result; 
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
