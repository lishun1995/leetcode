#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
*/

class Solution {
public:
	 int jump(vector<int>& nums)
	{
		//int len = nums.size();
		//vector<vector<int>> steps(len,nums[0]);

		vector<int> steps(nums.size(), nums[0]);
		int step = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (steps[step] >= nums.size() - 1) return step + 1;
			if (steps[step + 1] < i + nums[i]) steps[step + 1] = i + nums[i];
			if (steps[step] <= i) step++;
		}
		return step;
	}
};

int mainpsps()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(1);

	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(3);

	Solution s;
	int res = s.jump(nums);

	cout << res << endl;

	system("pause");
	return 0;
}