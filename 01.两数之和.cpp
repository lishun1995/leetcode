#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int> &nums,int target) 
	{
		vector<int> ans;
		map<int,int>  record;
		for (int i = 0; i < nums.size(); i++)
		{
			record[nums[i]] = i;
        }
		for(int i = 0; i < nums.size(); i++)
		{
			if(record.count(target - nums[i]) && record[target - nums[i]] != i)
			{
				ans.push_back(i);
				ans.push_back(record[target - nums[i]]);
				break;
			}
		}
		return ans;
	}
};

int maintwoSum()
{
	vector<int> nums;
	vector<int> ans;
	int target = 10;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
	nums.push_back(2);
    nums.push_back(5);
	nums.push_back(5);

	Solution s;
	ans = s.twoSum(nums,target);
	vector<int>::iterator it = ans.begin();
	for (; it != ans.end(); it++)
	{
		cout << *it << " ";
	}



	system("pause");
	return 0;
}