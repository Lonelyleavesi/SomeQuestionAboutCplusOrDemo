// 只有2个数出现1次的数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<bits/stdc++.h>

//a数组中 除了2个元素x,y 其他所有元素都出现了2次 找出x，y
void solution(int a[], int size) {
	int xORy = 0;
	int x;
	int y;
	for (int  i = 0; i < size; i++)
	{
		xORy ^= a[i];    //对a中每个数取异或，出现两次的数都抵消了 剩下的为X^Y
	}
	int mask = 1;
	for (; (mask&xORy) != 1; mask<<=1); //找到xORy 中 最后一位1的位置  x和y 在这一位的数值必定为一个是1  一个是0
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] & mask == 1)  //取对这一位造成影响的为x ，且x在这一位取值为1
		{
			x ^= a[i];
		}
		else
		{
			y ^= a[i];
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
