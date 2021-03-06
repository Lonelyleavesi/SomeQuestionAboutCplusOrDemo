// 华为面试题2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目 输入n行数，对于每一行都是一个string  其中如果包含非0~9 a~z A~Z的字符 是非法字符
//把非法字符 合法字符分开， 然后对合法字符去重， 然后输出 向左移1位 循环十次
//然后对字符进行排序 然后输出
//去重我是用的map

#include "pch.h"
#include <bits/stdc++.h>

using namespace std;
using std::string;
using std::vector;
using std::map;
bool isLegle(string str) {
	if (str.empty())
	{
		return true;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && !isalpha(str[i]) )
		{
			return false;
		}
	}
	return true;
}
//对str字符串从begin 到end进行翻转
void reserve(string &str, int begin ,int end){
	while (begin <= end)
	{
		swap(str[begin++],str[end--]);

	}
}

//循环左移一次
//比如 abcd  -> 先对2~end 位翻转adcb ->  在对所有位bcda
void leftShift1(string &str) {
	reserve(str,1,str.size()-1);
	reserve(str, 0, str.size()-1);
}


string unique(string str) { //通过map去重。 向map插入数据的时候是按照先后顺序插入的，最后一个一个字符取出就去重了
	map<char,char> temp;
	string a;
	for (size_t i = 0; i < str.size(); i++)
	{
		temp.insert(make_pair(str[i],str[i]));
	}
	for (std::map<char,char>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		a.push_back(it->second);
	}
	return a;
}

int main()
{
	string str;
	vector<string> strError;
	vector<string> strV;
	while (cin>>str)
	{
		if (isLegle(str))
		{
			strV.push_back(unique(str));
		}
		else
		{
			strError.push_back(str);
		}
	}
	//输出所有合法字符
	cout << "合法字符:" << endl;
	for (size_t i = 0; i < strV.size(); i++)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
	//输出所有非法字符
	cout << "非法字符:" << endl;
	for (size_t i = 0; i < strError.size(); i++)
	{
		cout << strError[i] << " ";
	}
	cout << endl;
	//对合法字符左移循环10次
	cout << "合法字符循环10次:" << endl;
	for (size_t i = 0; i < strV.size(); i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			leftShift1(strV[i]);
		}
		cout << strV[i] << " ";
	}
	cout << endl;
	//sort(strV.begin(),strV.end());
	//写一个简单的插入排序
	cout << "合法字符排序:" << endl;
	for (size_t i = 0; i < strV.size(); i++)
	{
		for (size_t j = i+1; j < strV.size(); j++)
		{
			if (strV[j] < strV[i])
			{
				string temp = strV[j];
				strV[j] = strV[i];
				strV[i] = temp;
			}
		}
	}
	for (size_t i = 0; i < strV.size(); i++)
	{
		cout << strV[i] << " ";
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