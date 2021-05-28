#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
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