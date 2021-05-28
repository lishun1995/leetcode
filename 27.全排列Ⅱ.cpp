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
	//vector<vector<int>> permuteUnique(vector<int>& nums){
	//	vector<vector<int>>  res;
	//	vector<int> rec;
	//	int index = 0;
	//	map<int,int> selected;
	//	if(nums.size() == 0)
	//	{
	//		return res;
	//	}
	//	getPermuteUnique(res,selected,nums,0,rec);
	//	return res;
	//}

	//void getPermuteUnique(vector<vector<int>> &res,map<int,int> &selected,vector<int>& nums,int index,vector<int> &rec)
	//{
	//	map<int,bool> flag;
	//	if(index == nums.size())
	//	{
	//		res.push_back(rec);
	//		return;
	//	}

	//	for (int i = 0; i < nums.size(); i ++)
	//	{
	//		if (selected[i] != 0 || flag[nums[i]])			//若已经选择过则跳过
	//			continue;
	//		selected[i] = 1;
	//		flag[nums[i]] = true;
	//		rec.push_back(nums[i]);
	//		getPermuteUnique(res,selected,nums,index + 1,rec);
	//		selected[i] = 0;
	//		rec.pop_back();
	//	}
	//}

	vector<string> Permutation(string str) {
		vector<string> result;
		if(str.size() == 0)
			return result;
		string strTemp;
		map<int,int> selected;
		int k = 0;
		getPermutation(result,selected,str,strTemp,k);

		return result;
	}

	void getPermutation(vector<string> &result,map<int,int> &selected,string &str,string &strTemp,int k)
	{
		map<int,bool> flag;
		if(k == str.size())
		{
			result.push_back(strTemp);
			return;
		}
			

		for(int i = 0; i < str.size(); i++)
		{
			if(selected[i] == 1 || flag[str[i]])
				continue;
			selected[i] = 1;
			flag[str[i]] = true;
			strTemp += str[i];
			getPermutation(result,selected,str,strTemp,k+1);
			selected[i] = 0;
			strTemp.pop_back();
		}
	}

};


int main222()
{
	/*
	vector<vector<int>> res;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	*/
	string str = "abc";
	vector<string> res;
	Solution s;
	res = s.Permutation(str);

	vector<string>::iterator iter = res.begin();
	for (iter; iter != res.end(); iter++)
	{
		cout << *iter << endl;
	}

	/*
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
	*/

	//std::vector<int> vec;

	//vec.push_back(6);
	//vec.push_back(-17);
	//vec.push_back(12);

	//// 删除第二个元素 (vec[1])
	//vec.erase(vec.begin() + 1);

	getchar();
	return 0;
}