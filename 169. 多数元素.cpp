#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	//BM（Boyer-Moore Majority Vote Algorithm）投票法：：设置一个计数器，在遍历数组的时候，如果是这个数，则计数器加1，否则减1，该方法用来计数超过一半的数非常方便
	//执行用时 20ms 内存消耗 8.6 MB
	int majorityElement(vector<int>& nums) {
		int cnt = 0,res = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(cnt == 0)
			{
				res = nums[i];
				cnt++;
			}
			else if(nums[i] == res)
					cnt++;
			else
					cnt--;
			}
		return res;
	}

	//直接排序：执行用时 56ms 内存消耗 9.1 MB
	int majorityElement2(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		return nums[nums.size()/2];
	}

	//HashMap计数: 执行用时 48ms //内存消耗 9.2 MB
	int majorityElement3(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
		//HashMap count
		map<int,int> miCount;
		for(int i = 0; i < nums.size(); i++)
		{
			if(miCount.find(nums[i]) != miCount.end())
			{
				miCount[nums[i]]++;
				if(miCount[nums[i]] > nums.size()/2)
					return nums[i];
			}
			else
			{
				miCount.insert(make_pair(nums[i],1));
			}
		}
		return 0;
	}

	//二进制位运算：利用二进制位运算，检查每一个二进制位是否为1，如果是就累加count， 如果>n/2就置为1。
	//执行用时 40ms
	int majorityElement4(vector<int>& nums) {
		int res = 0;
		for(int i = 0; i < 31; i++)
		{
			int mask = 1 << i;
			int iCount = 0;
			for(int j = 0; j < nums.size(); j++)
			{
				if((nums[j]&mask) != 0)
					iCount++;
			}
			if(iCount > nums.size()/2)
				res = res|mask;
		}
		return res;
	}

	//BM（Boyer-Moore Majority Vote Algorithm）投票法，设置两个计数器，如果是两个数中的一个，则对应的计数器加1，如果不是这两个数中的任何一个，则两个计数器都减1。如果计数器为0了，则统计当前这个数。那么如果一个数出现次数超过1/3，则最后必然出现在统计的数中，但是我们不确定得到的这两个数出现次数是否超过1/3，因此最后需要验证一下。该算法的时间复杂度是O(n)，空间复杂度是O(1)
	//执行用时 40ms 内存消耗15.2 MB
	vector<int> majorityElementII1(vector<int>& nums) {
		vector<int> res;
		if(nums.size() == 0)
			return res;
		int num1,num2,count1 = 0,count2 = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			int val = nums[i];
			if(val == num1)
				count1++;
			else if(val == num2)
				count2++;
			else if(count1 == 0)
			{
				count1++;
				num1 = val;
			}else if(count2 == 0)
			{
				count2++;
				num2 = val;
			}else
			{
				count1--;
				count2--;
			}
		}
		count1 = 0,count2 = 0;
		for(int i = 0;i < nums.size();i++)
		{
			int val = nums[i];
			if(val == num1)
				count1++;
			else if(val == num2)
				count2++;
		}
		if(count1 > nums.size()/3)
		{
			res.push_back(num1);
		}
		if(count2 > nums.size()/3)
		{
			res.push_back(num2);
		}
		return res;
	}

	//Partition方法：可以调用基本快速排序中的partition方法，该方法可以在线性时间内，按照某个数将数组分为两部分，其中左边是比这个数小的数，右边是比这个数大的数。在这个题目中，我们要找到出现次数超过1/3的数，那么这样的数最多有两个，利用partition找出应该出现在数组1/3以及2/3处的值，则出现超过1/3的数必然在这两个数中。然后再验证这两个数是不是解。这种解法期望的时间复杂度是O(nlogn)，但是在最坏情况下时间复杂度依然是O(N^2)。Partition方法可以通过Leetcode上面的测试用例，但是耗时非常多。
	vector<int> majorityElementII2(vector<int>& nums) {
		vector<int> res;
		if(nums.size() == 0) return res;
		int iLength = nums.size(),left = 0,right = iLength - 1;
		int num1 = 0, num2 = 0,pos = 0;
		while((pos = partition(nums,left,right)) != iLength/3)
		{
			pos < iLength/3 ? left=pos+1 : right=pos-1;
		}
		num1 = nums[iLength / 3];
		left = 0,right = iLength - 1;
		while((pos = partition(nums,left,right)) != iLength* 2/3)
		{
			pos < iLength*2/3? left=pos+1 : right=pos-1;
		}
		num2 = nums[iLength * 2/ 3];
		int count1 = 0,count2 = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == num1)
				count1++;
			else if(nums[i] == num2)
				count2++;
		}
		if(count1 > iLength/3)
			res.push_back(num1);
		if(count2 > iLength/3)
			res.push_back(num2);
		return res;
	}

public:
	int partition(vector<int>& nums,int left,int right)
	{
		//left为容器中最后一个值排序后所在的位置的下标
		int val = nums[right];
		for(int i = left; i < right; i++)
		{
			if(nums[i] < val)
			{ 
				swap(nums[left++],nums[i]);
			}
		}
		swap(nums[left],nums[right]);
		return left;
	}

};

int main169()
{
	vector<int> nums;
	vector<int> nums2;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(3);

	nums2.push_back(1);
	nums2.push_back(1);
	nums2.push_back(2);

	//sort(nums.begin(),nums.end());
	//int num1 = nums[nums.size()/3];
	//int num2 = nums[nums.size()*2/3];

	Solution s;
	int left = s.partition(nums2,0,nums2.size()-1);
	vector<int> res = s.majorityElementII2(nums);

	return 0;
}