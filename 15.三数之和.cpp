#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> res;
		if(nums.size() < 3)
			return res;
		int length = nums.size() - 2;
		sort(nums.begin(),nums.end());
		for (int i = 0; i < length; i++)
		{
			if(nums[i] > 0)
				break;
			int tagrt = 0 - nums[i];
			int left = i + 1,right = nums.size() - 1;
			vector<int> temp;
			while (left < right)
			{
				if((nums[left] + nums[right]) == tagrt)
				{
					temp.push_back(nums[i]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					res.push_back(temp);
					temp.pop_back();
					temp.pop_back();
					temp.pop_back();	
					int len = nums.size() - 1;
					while(left < len && nums[left] == nums[left + 1]) left++;
					while(right > 0 && nums[right] == nums[right - 1])right--;
					left++;
					right--;
				}else if((nums[left] + nums[right]) > tagrt) 
					right--;
				else left++;		
			}

			while(i != nums.size() - 1 && nums[i + 1] == nums[i])
				i++;
	     }
		return res;
	}
};

int main3Sum()
{
	//[-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]
	vector<int> nums;
	nums.push_back(-4);
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(-4);
	nums.push_back(-4);
	nums.push_back(4);
	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(0);

		
	//-4 -1 -1 0 1 2

	Solution s;
	vector<vector<int>> res;
	res = s.threeSum(nums);

	vector<vector<int>>::iterator iter = res.begin();
	for (iter;iter != res.end();iter++)
	{
		for (vector<int>::iterator subIter = (*iter).begin();subIter != (*iter).end();subIter++)
		{
			cout << *subIter << " ";
		}
	}


	getchar();
	return 0;
}