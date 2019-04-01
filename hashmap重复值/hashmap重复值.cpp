// hashmap重复值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include<map>
using namespace std;
using std::unordered_map;
using std::string;
using std::multimap;

int main()
{
	
	unordered_map<string ,int> test; //hash_map 可以有重复的值 但是没有覆盖？ 
	test.insert(make_pair("1",2));
	test.insert(make_pair("1", 1));
	std::unordered_map<string, int>::iterator it;
	it = test.find("1");    //找到的为 2，  没有覆盖
	cout << it->second<<endl;
	//it++;   运行会出错 1:2 的下一个并不是1:1
	//cout << it->second << endl;
	multimap<string, int> testMmp; //实验证明 mulimap 在内部是升序排列的
	testMmp.insert(make_pair("1",1));
	testMmp.insert(make_pair("1", 1));
	testMmp.insert(make_pair("2", 4)); //先插入4后插入3， find “2” 返回的是先插入的
	testMmp.insert(make_pair("2", 3));
	std::multimap<string, int>::iterator it1;
	for (std::multimap<string,int>::iterator mmit = testMmp.begin(); mmit != testMmp.end(); mmit++)
	{
		cout << mmit->first << ":" << mmit->second<<endl;
	}
	it1 = testMmp.find("2"); //找到的是第一个出现的“2”
	cout << it1->first << ":" << it1->second << endl;
	it1++;
	cout << it1->first << ":" << it1->second << endl;

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
