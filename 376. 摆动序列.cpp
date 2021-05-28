#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	int wiggleMaxLength_tanxin(vector<int>& nums)
	{
		if(nums.size() == 1)
			return 1;

		int	preDiff = 0;
		int curDiff = 0;
		int res = 1;
		for(int i = 1; i < nums.size(); i++)
		{
			int curDiff = nums[i] - nums[i-1];
			if((curDiff>0 && preDiff<=0) || (curDiff<0 && preDiff >= 0))
			{
				res++;
				preDiff = curDiff;
			}
		}
		return res;
	}

	int wiggleMaxLength_dongtaiguihua01(vector<int>& nums)
	{
		if(nums.size() == 1)
			return 1;

		int n = nums.size();
		int** dp = (int**)new int*[n];
		for(int i = 0; i < n; i++)
		{
			dp[i] = new int[2];
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				dp[i][j] = 0;
			}
		}

		int res = 1;
		int diff = 0;
		dp[0][0] = dp[0][1] = 1;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(nums[i] == nums[j])
					continue;
				diff = nums[i] > nums[j];
				dp[i][diff] = max(dp[i][diff],dp[j][diff^1]+1);
			}
		}

		res = max(dp[n-1][0],dp[n-1][1]);

		for(int i = 0; i < n; i++)
		{
			delete[] dp[i];
		}

		delete[] dp; 
		
		return res;
	}

	int wiggleMaxLength_dongtaiguihua02(vector<int>& nums)
	{
		if(nums.size() == 1)
			return 1;

		int n = nums.size();
		int** dp = (int**)new int*[n];
		for(int i = 0; i < n; i++)
		{
			dp[i] = new int[2];
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				dp[i][j] = 1;
			}
		}

		int res = 1;
		int diff = 0;
		dp[0][0] = dp[0][1] = 1;

		for(int i = 1; i < n; i++)
		{
			
			if(nums[i] == nums[i-1])
			{
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][1];
			}
			else
			{
				diff =  nums[i] > nums[i-1];
				dp[i][diff] =  dp[i-1][diff^1] + 1;
				dp[i][diff^1] = dp[i-1][diff^1];
			}

			/*
			if(nums[i] > nums[i-1])
			{
				dp[i][1] = dp[i-1][0] + 1;
				dp[i][0] = dp[i-1][0];
			}
			else
			{
				dp[i][0] = dp[i-1][1] + 1;
				dp[i][1] = dp[i-1][1];
			}
			*/
		}


		res = max(dp[n-1][0],dp[n-1][1]);

		for(int i = 0; i < n; i++)
		{
			delete[] dp[i];
		}

		delete[] dp; 

		return res;
	}

	int wiggleMaxLength_dongtaiguihua03(vector<int>& nums)
	{
		if(nums.size() == 1)
			return 1;

		int n = nums.size();
		int down = 1,up = 1;

		for(int i = 1; i < n; i++)
		{
			if(nums[i] > nums[i-1])
				up = down + 1;
			else if(nums[i] < nums[i-1])
				down = up + 1;

		}

		return max(down,up);
	}


public:
	//[0,1,0,3,2,3]
	int lengthOfLIS(vector<int>& nums) {

		if(nums.size() == 1)
			return 1;

		int n = nums.size();
		vector<int> dp(n,1);

		int maxres = 1;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(nums[j] < nums[i])
				{
					dp[i] = max(dp[i],dp[j]+1);
				}
			}
			maxres = max(maxres,dp[i]);
		}

		return maxres;
	}


public:
	//2 1 4 3
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();

		if(n == 1)
			return 1;

		vector<int> dp(n,1);
		vector<int> counts(n,1);
		int maxCount = 1;

		int maxres = 1;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(nums[j] < nums[i])
				{
					if(dp[i] < dp[j]+1)
					{
						dp[i] = dp[j]+1;
						counts[i] = counts[j];
					}
					else if(dp[i] == dp[j]+1)
					{
						counts[i] += counts[j];
					}
				}
			}
			maxres = max(maxres,dp[i]);
		}

		int results = 0;
		for(int i = 0; i < n; i++)
		{
			if(maxres == dp[i])
				results += counts[i];
		}

		return results;

	}


	bool increasingTriplet(vector<int>& nums) {

		/*
		if(nums.size() == 1)
			return 1;

		int n = nums.size();
		vector<int> dp(n,1);

		int maxres = 1;
		for(int i = 1; i < n; i++)
		{
			int tri = 1;
			for(int j = 0; j < i; j++)
			{
				if(nums[j] < nums[i])
				{
					if(dp[j]+1 > dp[i])
					{
						tri++;
						if(tri == 3)
							return true;
					}
					dp[i] = max(dp[i],dp[j]+1);
				}
			}
			maxres = max(maxres,dp[i]);
		}

		return maxres;
		*/

		if(nums.size() < 3)
			return false;

		int n = nums.size();

		int tail = nums[0];
		int head = nums[0];

		int length = 1;

		for(int i =1 ; i < n; i++)
		{
			if(nums[i] > tail)
			{
				length++;
				if(length == 3)
					return true;
				tail = nums[i];
			}
			else if(nums[i] > head && nums[i] < tail)
			{
				tail = nums[i];
			}
			//(nums[i] < tail && nums[i] <= head) || (nums[i] == tail)
			else if(i+1<n && nums[i]<nums[i+1] && nums[i]+1<=tail)
			{
				tail = nums[i];
				head = nums[i];
				length = 1;
			}
		}
		
		return false;

	}

public:
	int findLengthOfLCIS(vector<int>& nums) {
		if(nums.size() == 1)
			return 1;

		int m = nums.size();
		int ans = 0 ,acher = 0;
		for(int i = 1; i < m; i++)
		{ 
			if(nums[i] <= nums[i-1])
			{
				acher = i;
			}
			ans = max(ans, i - acher + 1);
		}
		return ans;
	}

};

int main()
{

	unsigned char ui_v = 256;
	int i_v = ui_v;

	printf("%d",i_v);

	/*
	int i_s = 0;
	int i_res = i_s^1;
	Solution s;

	vector<int> prices;

	//[0,1,0,3,2,3]
	prices.push_back(0);
	prices.push_back(1);
	prices.push_back(0);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(3);

	int ires = s.lengthOfLIS(prices);

	//[1,17,5,10,13,15,10,5,16,8]
	//prices.push_back(1);
	//prices.push_back(17);
	//prices.push_back(5);
	//prices.push_back(10);
	//prices.push_back(15);
	//prices.push_back(10);
	//prices.push_back(5);
	//prices.push_back(16);
	//prices.push_back(8);


	//int res1 = s.wiggleMaxLength_tanxin(prices);
	//res = s.wiggleMaxLength_dongtaiguihua01(prices);
	//int res2 = s.wiggleMaxLength_dongtaiguihua02(prices);
	//int res3 = s.wiggleMaxLength_dongtaiguihua03(prices);
	*/
	return 0;
}