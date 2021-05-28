#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/

class Solution {
public:
	 vector<vector<int>> subsets(vector<int>& nums){
		vector<vector<int>> result;
		vector<int> tmp;

		result.push_back(tmp);
		if(nums.empty()) 
			return result;

		getSubsets(result,0,nums,tmp);

		return result;
	}

	 void getSubsets(vector<vector<int>> &result,int pos,vector<int> &nums,vector<int> &tmp)
	 {
		 if(pos == nums.size())
		 {	
			 return;
		 }
		 
		 for (int i = pos; i < nums.size(); i++)
		 {
			 tmp.push_back(nums[i]);
			 result.push_back(tmp);
			 getSubsets(result,i + 1,nums,tmp);
			 tmp.pop_back();

		 }
	 }
};


int mainsziji()
{
	vector<vector<int>> res;
    vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution s;
	res = s.subsets(nums);

	vector<vector<int>>::iterator iter = res.begin();
	for (iter; iter != res.end(); iter++)
	{
		vector<int>::iterator it = iter->begin();
		for (it; it != iter->end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}