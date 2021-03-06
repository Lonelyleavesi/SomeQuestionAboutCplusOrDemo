// 华为笔试题1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//先输入一个数字 n 
//题目为 输入N 行数字， 不确定行数
//最后通过 空行结束
//然后对每一行数字轮流 截取n个数字 放置到一个string中，
//每一行都要轮流执行 直至每一行都被删除
//比如 3
//11111  22222 33333
//输入 为 111222333112233 中间有逗号
//我比较直观的 用list 储存n行数据， 其实直接用string 和substr也可以实现，当时没想到
//当时是以数字进行操作的，其实可以直接对string进行操作


#include "pch.h"
#include <bits/stdc++.h>
using std::string;
using namespace std;
using std::vector;
using std::list;
void strToint(const string &str, list<int> &nums) {
	if (str.empty())
	{
		return;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			nums.push_back(str[i] - '0');
		}
	}
}
vector<int> mergeIntBySubBySub( vector<list<int>>nums, int sub) {
	vector<int> temp;
	while (!nums.empty())
	{
		for (int i = 0; i< nums.size(); i++)
		{
			int count = 0;
			if (nums[i].empty())
			{
				nums.erase(nums.begin()+i);
				continue;
			}
			std::list<int>::iterator lit = nums[i].begin();
			while (count < sub)
			{
				temp.push_back(*lit);
				nums[i].pop_front();
				lit = nums[i].begin();
				if (nums[i].empty())
				{
					nums.erase(nums.begin() +i);
					break;
				}
				count++;
			}	
		}
	}
	return temp;
}
int main()
{
	vector<list<int>> nums; //初始size=0
	int sub;
	cin >> sub;		//一次插入多少数字
	list<int> tempnum;
	scanf_s("\n");
	string str;
	while (getline(cin,str))
	{
		tempnum.clear();
		strToint(str,tempnum);  //str转化成vector
		nums.push_back(tempnum);

	}
	for (int i = 0; i < nums.size(); i++)
	{
		for (std::list<int>::iterator j = nums[i].begin(); j != nums[i].end(); j++)
		{
			cout << *j;
		}
		cout << endl;
	}
	cout << endl;
	vector<int> merge;  //用于合并的数组
	merge = mergeIntBySubBySub(nums,sub);
	cout << merge[0]<<",";
	for (size_t i = 1; i < merge.size(); i++)
	{
		cout << merge[i] << ", ";
	}
}
//2, 5, 6, 1, 7, 4, 7, 9, 5, 3, 4, 7
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
