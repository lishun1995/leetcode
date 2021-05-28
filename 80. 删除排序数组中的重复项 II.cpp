#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace ls{
	class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			if(nums.size() == 0) return 0;
			int k = 0;
			for(int i = 0; i < nums.size(); i++)
			{
				if(k < 2 || nums[i] != nums[k - 2])
				{
					if(i != k)
					{
						nums[k++] = nums[i];
					}
					else
					{
						k++;
					}
				}
			}
			return k;
		}
	};
}


int main80()
{
	int arr[] = {0,0,1,1,1,1,2,3,3};
	vector<int> vec(arr,arr + sizeof(arr) / sizeof(int));
	ls::Solution s;
	int ret = s.removeDuplicates(vec);
	return 0;
}