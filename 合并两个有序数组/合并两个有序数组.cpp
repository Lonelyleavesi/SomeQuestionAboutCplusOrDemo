// 合并两个有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using std::vector;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (m <= 0)
	{
		nums1 = nums2;
	}
	if (n <= 0)
	{
		return;
	}
	int totalindex = nums1.size() - 1;
	int index1 = m - 1;
	int index2 = n - 1;
	while (index1 >= 0 && index2 >= 0)
	{
		if (nums1[index1] <= nums2[index2])
		{
			nums1[totalindex--] = nums2[index2--];
		}
		else
		{
			nums1[totalindex--] = nums1[index1--];
		}
	}
	if (index1 < 0)
	{
		for (int i = index2; i >= 0; i--) {
			nums1[i] = nums2[i];
		}
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
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
