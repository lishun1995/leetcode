#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int iLength = nums.size();
		k = k%iLength;
		int count = 0;
		for(int i = 0; count < iLength; i++)
		{
			int cur = i;
			int pre = nums[i];
			do{
				int next = (cur+k)%iLength;
				int temp = nums[next];
				nums[next] = pre;
				pre = temp;
				cur = next;
				count++;
			}while(i != cur);
		}
	}
};

int main189()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	int k = 5;
	Solution s;
	s.rotate(nums,k);
	vector<int>::iterator iter = nums.begin();
	for (iter; iter != nums.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}