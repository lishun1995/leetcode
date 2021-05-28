#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if(nums.size() == 0) return 1;
		sort(nums.begin(),nums.end());
		int num_max = nums[nums.size()-1];
		for(int i = 1; i < num_max; i++)
		{
			vector<int>::iterator iter = find(nums.begin(),nums.end(),i);
			if(iter == nums.end())
			{
				return i;
			}
		}
		return num_max+1;
	}

	int firstMissingPositive2(vector<int>& nums) {
		if(nums.size() == 0) return 1;
		int max_num = nums[0];
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i] > max_num)
				max_num = nums[i];
		}
		int *mem = new int[max_num + 1];
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] <= 0)
				continue;
			mem[nums[i]] = 1;
		}
		for(int i = 1; i < max_num+1; i++)
		{
			int nm = mem[i];
			if(mem[i] != 1)
				return i;
		}
		return max_num+1;
	}

	//nums不空缺任何数字的话，那么nums排序号后，数字就应该和索引对应
	int firstMissingPositive3(vector<int>& nums) 
	{
		if(nums.size() == 0) return 1;
		int iLen = nums.size();
		for(int i = 0; i < nums.size(); i++)
		{
			while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[nums[i] - 1],nums[i]);
			}
		}
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != i+1)
				return i+1;
		}
		return nums.size()+1;
	}
};

int main41()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(-1);
	nums.push_back(4);
	nums.push_back(1);
	Solution s;
	int res = s.firstMissingPositive3(nums);
	vector<int>::iterator iter = nums.begin();
	for(iter; iter != nums.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}