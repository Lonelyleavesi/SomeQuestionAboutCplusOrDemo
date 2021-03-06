// 数组中数最大间距.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
using std::vector;

class Solution {
public:
	class Bucket {
	public:
		~Bucket() {

		}
		int max = 0;
		int min = 0;
		bool hasNum = false;
	};

	int getBucketindex(int min, int num, int gap) {
		return (int)(num - min) / gap;
	};

	void putInBucket(unique_ptr<Bucket[]> &buckets, int num, int index) {
		if (buckets[index].hasNum == false) {
			buckets[index].hasNum = true;
			buckets[index].max = num;
			buckets[index].min = num;
		}
		else if (num > buckets[index].max) {
			buckets[index].max = num;
		}
		else if (num < buckets[index].min) {
			buckets[index].min = num;
		}
	}
	int maximumGap(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2)
			return 0;
		double min = nums[0];
		double max = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			max = nums[i] > max ? nums[i] : max;
			min = nums[i] < min ? nums[i] : min;
		}
		if (min == max)
			return 0;

		
		unique_ptr<Bucket[ ]> buckets(new Bucket[nums.size()]);
		int gap = (int)ceil((max - min)/nums.size()-1);

		for (int i = 0; i < nums.size(); i++)
		{
			int index = getBucketindex(min,nums[i],gap);
			putInBucket(buckets, nums[i],index);
		}
		int maxGap = buckets[0].max - buckets[0].min;
		int pre = buckets[0].max;
		for (int i = 1; i < nums.size(); i++)
		{
			if (buckets[i].hasNum != false)
			{
				maxGap = (buckets[i].min - pre)>maxGap? (buckets[i].min - pre):maxGap;
				pre = buckets[i].max;
			}
		}	
		nums.clear();
		buckets.release();
		return maxGap;
	}

};
int main()
{
	vector<int> a = { 12,2,5,74,9,15,7,1,5,6,7,5,1,9,7,5,64,48,97,4,54,97,94,9,546,-5,1,-4,489 };
	Solution s;
	int max = s.maximumGap(a);
    std::cout << max;
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
