// hash_map初体验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <string>
#include <iostream>
#include<unordered_map>

using namespace std;

//define the class
class ClassA {
public:
	ClassA(int a) :c_a(a) {}
	int getvalue()const { return c_a; }
	void setvalue(int a) { c_a; }
private:
	int c_a;
};

//1 define the hash function
struct hash_A {
	size_t operator()(const class ClassA & A)const {
		//  return  hash<int>(classA.getvalue());
		return A.getvalue();
	}
};

//2 define the equal function
struct equal_A {
	bool operator()(const class ClassA & a1, const class ClassA & a2)const {
		return  a1.getvalue() == a2.getvalue();
	}
};

int main()
{
	unordered_map<ClassA, string, hash_A, equal_A> hmap;
	ClassA a1(12);
	hmap[a1] = "I am 12";
	ClassA a2(198877);
	hmap[a2] = "I am 198877";


	cout << hmap[a1] << endl;
	cout << hmap[a2] << endl;
	//hash_map的迭代器  返回key 和value
	std::unordered_map<ClassA, string>::const_iterator it;
	it =  hmap.find(a1);
	cout<<it->first.getvalue()<<"  is  "<<it->second<<endl;
	cout << "hmap.bucket_count():" << hmap.bucket_count() << endl;;


	size_t a = 'a'^15;
	cout << a;

	return 0;
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
