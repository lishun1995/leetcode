#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	//BM��Boyer-Moore Majority Vote Algorithm��ͶƱ����������һ�����������ڱ��������ʱ�����������������������1�������1���÷���������������һ������ǳ�����
	//ִ����ʱ 20ms �ڴ����� 8.6 MB
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

	//ֱ������ִ����ʱ 56ms �ڴ����� 9.1 MB
	int majorityElement2(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		return nums[nums.size()/2];
	}

	//HashMap����: ִ����ʱ 48ms //�ڴ����� 9.2 MB
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

	//������λ���㣺���ö�����λ���㣬���ÿһ��������λ�Ƿ�Ϊ1������Ǿ��ۼ�count�� ���>n/2����Ϊ1��
	//ִ����ʱ 40ms
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

	//BM��Boyer-Moore Majority Vote Algorithm��ͶƱ��������������������������������е�һ�������Ӧ�ļ�������1������������������е��κ�һ��������������������1�����������Ϊ0�ˣ���ͳ�Ƶ�ǰ���������ô���һ�������ִ�������1/3��������Ȼ������ͳ�Ƶ����У��������ǲ�ȷ���õ��������������ִ����Ƿ񳬹�1/3����������Ҫ��֤һ�¡����㷨��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
	//ִ����ʱ 40ms �ڴ�����15.2 MB
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

	//Partition���������Ե��û������������е�partition�������÷�������������ʱ���ڣ�����ĳ�����������Ϊ�����֣���������Ǳ������С�������ұ��Ǳ��������������������Ŀ�У�����Ҫ�ҵ����ִ�������1/3��������ô�����������������������partition�ҳ�Ӧ�ó���������1/3�Լ�2/3����ֵ������ֳ���1/3������Ȼ�����������С�Ȼ������֤���������ǲ��ǽ⡣���ֽⷨ������ʱ�临�Ӷ���O(nlogn)��������������ʱ�临�Ӷ���Ȼ��O(N^2)��Partition��������ͨ��Leetcode����Ĳ������������Ǻ�ʱ�ǳ��ࡣ
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
		//leftΪ���������һ��ֵ��������ڵ�λ�õ��±�
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