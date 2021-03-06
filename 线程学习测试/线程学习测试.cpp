// 线程学习测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

class thread_test {
public:

	//类中返回线程运行
	thread run() {
		return thread(&thread_test::demo,this,5);
	}

	void static demostatic() {
		for (int i = 0; i < 6; i++)
		{
			cout << 6 << endl;
		}
	}
	void demo(int num ) {
		for (int i = 0; i < num; i++)
		{
			cout << num << endl;
		}
	}
};



void thread01()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Thread 01 is working ！" << endl;
		Sleep(100);
	}
}
void thread02(int num)  //带参数
{
	for (int i = 0; i < num; i++)
	{
		cout << "Thread 02 is working ！" << endl;
		Sleep(200);
	}
}

#include <mutex> //互斥锁

mutex mu;  //线程互斥对象
int totalNum = 100;

void thread03()
{
	//mutex mu; 定义成局部互斥锁没用
	while (totalNum > 0)
	{
		mu.lock(); //同步数据锁
		cout << totalNum <<"from thread03"<< endl;
		totalNum--;
		mu.unlock();  //解除锁定
	}
}
void thread04()
{
	//mutex mu; 定义成局部互斥锁没用 
	while (totalNum > 0)
	{
		mu.lock();
		cout << totalNum << "from thread04" << endl;
		totalNum--;
		mu.unlock();
	}
}

int main()
{
	//thread task01(thread01);
	//thread task02(thread02,5);   //带参数的线程

	//主线程等待子线程
	/*task01.join();
	task02.join();*/

	//主线程与子线程互不干扰 即同时运行
	/*task01.detach();
	task02.detach();
	//好像定义了线程默认启用方式就是detach
	*/

	/*for (int i = 0; i < 5; i++)
	{
		cout << "Main thread is working ！" << endl;
		Sleep(200);
	}*/

	//------------------------------------------------------------------------
	//带公共资源的两个线程 需要互斥锁
	/*thread task03(thread03);
	thread task04(thread04);
	task03.detach();
	task04.detach();*/


	//--------------------------------------------------------------
	//测试线程调用类中的函数
	thread_test test;
	//thread classtest1(&thread_test::demo, test,5); 
	////注意2点：1、类中的函数需要用到引用。2、需要传入类的对象
	//classtest1.join();

	//-----------------------------------------------------------------------
	//测试线程调用类中线程成员
	//thread classtest2 = test.run();

	//调用静态函数  注意：不需要对象 不需要引用。  可能因为静态变量是所有这个类的对象共享的 
	//在编译时 就初始化好了
	thread classtest3(thread_test::demostatic);
	classtest3.join();
	system("pause");
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
