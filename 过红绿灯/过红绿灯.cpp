// 过红绿灯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//输入一个数n 表示有多少个红绿灯，起点到第一个红绿灯的距离为150，最后一个红绿灯到终点的距离为150
//输入每个红绿灯亮的时间ti
//每个红绿灯红灯的时间和绿灯的时间都是ti
//输入一个速度v{5,10,15,20,25,30,50}
//不能闯红灯， 速度能直接从v变成0，也能直接从0变成v
//求到终点的时间
//首先总路程为150（n+1） 然后难点就在找到达每个路灯的时候 红绿灯情况
//可以手动画图 总结出来、、 此时的t 如果 满足 (t % 2ti) < ti 就是绿灯 否则就是红灯
//需要注意一点 当速度为20的时候time  不能用% 来取模 因为150/20 会出现浮点数
//于是我手动写了一个mod函数
#include "pch.h"
#include<bits/stdc++.h>
using namespace std;
float mod(float m , int n) { //自己手动写的mod函数 主要解决当速度为20的时候 会出现浮点数的mod
	while (m >= n)
	{
		m -= n;
	}
	return m;
}

int main()
{
	int lightN;
	cin >> lightN;
	int *t = new int[lightN];
	for (size_t i = 0; i < lightN; i++)
	{
		cin >> t[i];
	}
	float v;
	cin >> v;
	int loc = 0;
	float time = 0;
	int sub = 150;
	int end = 150 * (lightN + 1);
	loc += sub;
	time += sub / v;
	int lightID = 0;
	while (loc < end)
	{
		if (mod(time, (2 * t[lightID])) < t[lightID])  //这种情况代表是绿灯
		{
			loc += sub;
			time += sub / v;
			lightID++;
		}
		else //否则就得等到下个绿灯
		{
			time = int(((time / t[lightID]) + 1))*t[lightID];  //记得int() 不然time在这里会变成浮点数，一个灯下个绿灯的时间应该是个整数
		}
	}
	int result = time;
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
