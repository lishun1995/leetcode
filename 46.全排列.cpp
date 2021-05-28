#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
输入: [1,2,3]
输出:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Solution {
public:
	 vector<vector<int>> permute(vector<int>& nums){
		 vector<vector<int>>  res;
		 vector<int> rec;
		 int index = 0;
		 map<int,int> selected;
		 if(nums.size() == 0)
		 {
			 return res;
		 }
		 getPermute(res,selected,nums,0,rec);
		 return res;
	}

	 void getPermute(vector<vector<int>> &res,map<int,int> &selected,vector<int>& nums,int k,vector<int> &rec)
	 {	
		 if(k == nums.size())
		 {
			 res.push_back(rec);
			 return;
		 }
		 
		 for (int i = 0; i < nums.size(); i ++)
		 {
			 if (selected[i] != 0)							//若已经选择过则跳过
			    continue;
			 selected[i] = 1;
			 rec.push_back(nums[i]);
			 getPermute(res,selected,nums,k + 1,rec);
			 selected[i] = 0;
			 rec.pop_back();
		 }
	  }
};

int mainujki()
{
	vector<vector<int>> res;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution s;
	res = s.permute(nums);

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

	//std::vector<int> vec;

	//vec.push_back(6);
	//vec.push_back(-17);
	//vec.push_back(12);

	//// 删除第二个元素 (vec[1])
	//vec.erase(vec.begin() + 1);

	getchar();
	return 0;
} 