// hashmap重复值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include<map>
using namespace std;
using std::unordered_map;
using std::string;
using std::multimap;
using std::unordered_multimap;

int main()
{
	
	unordered_map<string ,int> test; //hash_map 可以有重复的值 但是没有覆盖？下标访问可以覆盖 
	test.insert(make_pair("1",2));
	test.insert(make_pair("1", 1));
	std::unordered_map<string, int>::iterator it;
	it = test.find("1");    //找到的为 2，  没有覆盖
	cout << it->second<<endl;
	//it++;   运行会出错 1:2 的下一个并不是1:1
	//cout << it->second << endl;

	cout << "hash_mulitimap test \n";
	unordered_multimap<string, int> hash_mmp;  //hash_mulimap 可以多个重复值 按升序排列的
	hash_mmp.insert(make_pair("2", 4));//先插入4后插入3， find “2” 返回的是先插入的
	hash_mmp.insert(make_pair("2", 3));
	hash_mmp.insert(make_pair("1", 1));//从这里可以看出hash_mmp的储存方式是顺序访问，比如先插入24后插入1 1 ，
	//24的迭代器下一个就能到11
	hash_mmp.insert(make_pair("1", 2));
	std::unordered_multimap<string, int>::iterator hit;
	for (hit = hash_mmp.begin(); hit!= hash_mmp.end() ; hit++)
	{
		cout << hit->first << ":" << hit->second << endl;
	}
	cout << "find test \n";
	hit = hash_mmp.find("1");
	cout << hit->first << ":" << hit->second << endl; // 1:1 
	hit++;
	cout << hit->first << ":" << hit->second << endl;//1:2
	hit++;
	cout << hit->first << ":" << hit->second << endl;//2:4  这里我有一些疑问，不是说hash表是无序的？
	//但是我从1:1 访问到 2:4 和插入顺序有关？ 是的果然，我开始是先插入1后插入2  ，现在这个会报错



	cout << "mulitimap test \n";
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
