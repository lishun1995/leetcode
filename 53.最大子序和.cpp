#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums){
		int _max = nums[0];
		int currentMax = _max;
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i] + currentMax > nums[i])
			{
				_max = max(_max,nums[i] + currentMax);
			}
		}

		return _max;
	}
};


int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	

	getchar();
	return 0;
}