#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zeros = 0, ones = 0;
		for(unsigned int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0) zeros++;
			if(nums[i] == 1) ones++;
		}

		for(unsigned int i = 0; i < nums.size(); i++)
		{
			if(i<zeros) nums[i] = 0;
			if(i>=zeros && i < zeros+ones) nums[i] = 1;
			if(i>= zeros+ones) nums[i]=2;
		}
	}
};

int main75()
{
	int arr[] = {2,0,2,1,1,0};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	Solution().sortColors(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}