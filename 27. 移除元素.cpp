#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = 0; //数组的新长度
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != val)
			{
				if(k != i)
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


int main27()
{
	int arr[] = {3,5,2,2,3};
	vector<int> vec(arr,arr + sizeof(arr) / sizeof(int));
	int val = 2;
	Solution s;
	int ret = s.removeElement(vec,2);
	cout << ret << endl;
	return 0;
}
