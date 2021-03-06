// 百度笔试动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*问题为 n个小兵有物理攻击魔法攻击， 将小兵放进三个连中， 第一个连的战斗力W1 为小兵物理攻击的合
第二个连则为 魔法攻击  第三个连为物理攻击和魔法攻击的平均值， 由于漏看了需要等分，所以本解法针对的
为三个队列任意分战斗力总和最大情况。 用贪心算法， 通过对每个小兵战力分配最大来满足总战力最大
小兵的个数绝对为3n
如果需要等分，目前思路为：每次分配3个小兵， 也是3个小兵任意组合的6种情况局部最优 来满足全局最优
*/
#include "pch.h"
#include <bits/stdc++.h>
using namespace std;
class Solider
{
public:
	Solider(float x, float y) { pA = x; mA = y; };
	Solider() { pA = 0; mA = 0; };

	float pA;  //物理攻击
	float mA;	//魔法攻击
};



float bestLoc(const Solider &s)
{
	float maxNum = 0;
	float mid = (s.mA + s.pA) / 2.0;
	if (s.mA > s.pA  || s.mA > mid)
	{
		//printf("%f \n",s.mA);
		return s.mA;
	}
	if (s.pA > s.mA || s.pA > mid)
	{
		//printf("%f \n", s.pA);
		return s.pA;
	}
	//printf("%f \n", mid);
	return mid;
}

int main()
{
	int sNum;
	cin >> sNum;
	Solider *S = new Solider[sNum];
	float x, y;
	for (int i = 0; i < sNum; i++)
	{
		cin >> x ;
		S[i].pA = x;
	}
	for (int i = 0; i < sNum; i++)
	{
		cin >> y;
		S[i].mA = y;
	}
	float Best = 0;
	for (int i = 3; i < sNum; i += 3)
	{
		Best += bestLoc(S[i]);
	}
	printf("%.2f",Best);
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
