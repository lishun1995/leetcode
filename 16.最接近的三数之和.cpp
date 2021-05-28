#include <iostream>
#include<sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int>& nums , int target) {

		if(nums.size() < 3)
			return 0;

		int len = nums.size() - 2;
		sort(nums.begin(),nums.end());
		int res = nums[0] + nums[1] + nums[2];
		int dValue = abs(target - res);
		int l = 0, r = 0,sum;

		for (int i = 0; i < len; i++)
		{
			l = i + 1;
			r = nums.size() - 1;
			if(3 * nums[i] > target)
				break;
			while (l < r)
			{
				sum = nums[i] + nums[l] + nums[r];
				if(sum < target)
				{
					l++;
				}else if(sum > target)
				{
					r--;
				}else
				{
					return target;
				}
				if(abs(target - sum) < dValue)
				{
					res = sum;
					dValue = abs(target - sum);
				}
			}
		}

		return res;

	}
};

int mainThree()
{
	vector<int> nums;
	nums.push_back(-4);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	nums.push_back(-4);

	Solution s;
	int res = s.threeSumClosest(nums,8);
	cout << res << endl;

	getchar();
	return 0;
}