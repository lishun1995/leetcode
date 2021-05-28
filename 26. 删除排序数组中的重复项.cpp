#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int k = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[k] != nums[i])
			{
				nums[++k] = nums[i];
			}
		}
		return k+1;
	}
};

int main26()
{
	int arr[] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> vec(arr,arr + sizeof(arr) / sizeof(int));
	Solution s;
	int ret = s.removeDuplicates(vec);
	return 0;
}

