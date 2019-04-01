// sizeof.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
using std::string;
union uniona{
	int a;
	float b;
	double c;
};


class foo
{
public:
	foo() {};
	~foo() {};

	virtual void s() = 0;
	
private:

};



struct str_hash {
	size_t operator()(const string& str) const
	{
		unsigned long __h = 0;
		for (size_t i = 0; i < str.size(); i++)
			__h = 5 * __h + str[i];
		return size_t(__h);
	}
}shz;

int f() {
	int a;
	int a1;
	return 0;
}

struct duiqi
{
	int a;
	char d[5];
	char b;
	short c;
};

int main()
{
	int* a = (int *)malloc(10);
	uniona s;
	int b[10] = { 0 };
	std::cout << sizeof(int) << endl;;

	string str = "123456";
	unsigned long __h = 0;
	for (size_t i = 0; i < str.size(); i++)
		__h = 5 * __h + str[i];

	cout << __h <<"  "<<sizeof(str)<<endl;
	cout << "sizeof(str_hash):" <<sizeof(shz)<<endl;
	cout <<"sizeof(f()):"<< sizeof(f()) << endl;

	char c = 'a';
	cout << "sizeof(c):" << sizeof(c) << endl;
	char cs[10] = {'a','b'};
	cout << "sizeof(cs):" << sizeof(cs) << endl;

	cout << "sizeof(foo):" << sizeof(foo) << endl;
	cout << "sizeof(Union uniona):" << sizeof(s) << endl;
	cout << "sizeof(duiqi):" << sizeof(duiqi) << endl;


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
