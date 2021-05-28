#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m+n-1;
		m--;n--;

		while(m >= 0 && n >= 0)
		{
			if(nums1[m] < nums2[n])
			{
				nums1[pos--] = nums2[n--];
			}
			else
			{
				nums1[pos--] = nums1[m--];
			}
		}

		while(n >= 0)
		{
			nums1[pos--] = nums2[n--];
		}
	}
};

int main88()
{
	int m = 3;
	int n = 3;

	vector<int> nums1(m+n,0);
	nums1[0] = 1;
	nums1[1] = 2;
	nums1[2] = 3;

	vector<int> nums2(n,0);
	nums2.resize(n);
	nums2[0] = 2;
	nums2[1] = 5;
	nums2[2] = 6;

	Solution().merge(nums1, m, nums2, n);
	for (int num = 0; num < m+n; num++)
	{
		cout << nums1[num] << " ";
	}
	cout << endl;
	return 0;
}