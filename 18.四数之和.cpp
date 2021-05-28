#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<vector<int>> res;
		vector<int>  temp;

		if(len < 4)
			return res;

		sort(nums.begin(),nums.end());

		for (int i = 0; i < len - 3; i++)
		{
			//if(nums[i]  target) break;
			//跳过重复的数据
			if(i > 0 && nums[i] == nums[i-1]) continue;
			for (int j = len - 1; j > i + 2; j--)
			{
				//跳过重复的数据
				if(j < len - 1 && nums[j] == nums[j+1]) continue;
				int  l = i + 1;
				int  r = j - 1;
				while(l < r)
				{
					int total = nums[i] + nums[j] + nums[l] + nums[r];
					if(total == target)
					{
						temp.push_back(nums[i]);
						temp.push_back(nums[l]);
						temp.push_back(nums[r]);
						temp.push_back(nums[j]);

						res.push_back(temp);
						temp.clear();

						//跳过重复的数据
						while(l < r &&  nums[l] == nums[l+1]) l++;
						while(l < r &&  nums[r] == nums[r-1]) r--;
						l++;
						r--;
					}

					if(total > target)
					{
						
						r--;
					}
					else if(total < target)
					{
						l++;
					}
				}
			}
		}
		
		return res;
	}
};

//[-3,-1,0,2,4,5]

//nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
/*
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
int mainfourSum()
{
	vector<int> nums;
	vector<vector<int>> ans;
	int target = 0;

	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(-2);
	nums.push_back(2);

	/*nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
    */
	//nums.push_back(-3);
	//nums.push_back(-1);
	//nums.push_back(0);
	//nums.push_back(2);
	//nums.push_back(4);
	//nums.push_back(5);

	Solution s;
	ans = s.fourSum(nums,target);

	vector<vector<int>>::iterator iter = ans.begin();
	for (iter; iter != ans.end(); iter++)
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