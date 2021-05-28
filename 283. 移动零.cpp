#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	int moveZeroes(vector<int>& nums) {
		int k = 0;
		for(unsigned int i = 0; i < nums.size(); i++)
		{
			if(nums[i])
			{
				if(k!=i)
					swap(nums[k++],nums[i]);
				else
					k++;
			}
		}
		return k;
	}


};


int main283()
{
	int arr[] = { 0,1,0,3,12,2,3,4,5,6};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	int res = Solution().moveZeroes(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}