#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

namespace maxProfit{
	class Solution {
	public:
		int maxProfit121_violence(vector<int>& prices) {
			if(prices.size() <= 1)
				return 0;

			int maxRes = 0;
			for(int i = 0; i < prices.size(); i++)
			{
				for(int j = i+1; j < prices.size(); j++)
				{
					int tmpValue = prices[j] - prices[i];
					if(tmpValue > maxRes)
						maxRes = tmpValue;
				}
			}
			return maxRes;
		}


		int maxProfit121_dynamic(vector<int>& prices) {
			if(prices.size() <= 1)
				return 0;

			int maxRes = 0;
			int minPrice = prices[0];

			for(int i = 1; i < prices.size(); i++)
			{
				if(prices[i] < minPrice)
					minPrice = prices[i];
				else if(maxRes < prices[i] - minPrice)
				{
					maxRes = prices[i] - minPrice;
				}
			}
			return maxRes;
		}

		int maxProfit122_greedy(vector<int>& prices) {
			if(prices.size() <= 1)
				return 0;

			int maxRes = 0;
			for(int i = 0; i < prices.size(); i++)
			{
				if(prices[i] < prices[i+1])
				{
					maxRes += prices[i+1] - prices[i];
				}
			}
			return maxRes;
		}

		int maxProfit122_violence(vector<int>& prices) 
		{
			if(prices.size() <= 1)
				return 0;

			int len = prices.size();
			this->res = 0;
			dfs(prices,0,len,0,0);
			return res;
		}

	/**
     * @param prices 股价数组
     * @param index  当前是第几天，从 0 开始
     * @param status 0 表示不持有股票，1表示持有股票，
     * @param profit 当前收益
     */
		void dfs(vector<int>& prices,int index,int len,int status,int profit)
		{
			if(index == len)
			{
				printf("%d:%d res:%d\n",index,profit,res);
				res = max(res,profit); 
				return;
			}

			dfs(prices, index+1,len,status,profit);

			if(status == 0)
			{
				dfs(prices, index + 1, len, 1, profit-prices[index]);
			}
			else
			{
				dfs(prices, index + 1, len, 0, profit+prices[index]);
			}
		}
		
		int maxProfit122_dongtaiguihua(vector<int>& prices) 
		{
			if(prices.size() <= 1)
				return 0;

			int res = 0;

			int len = prices.size();

			int** dp  = (int**)new int*[len];
			for(int i = 0; i < len; i++)
			{
				dp[i] = new int[2];
			}

			dp[0][0] = 0;
			dp[0][1] = -prices[0];

			for(int i = 1; i < prices.size(); i++)
			{
				dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
				dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
			}

			res = dp[len-1][0];

			for(int i = 0; i < len; i++)
			{
				delete[] dp[i];
			}
		    delete[] dp;
			
			
			return res;
		}


	private:
		int res;	
	};

};

//
int main121()
{
	//[7,1,5,3,6,4]
	vector<int> prices;

	/*
	prices.push_back(7);
	prices.push_back(1);
	prices.push_back(5);
	prices.push_back(3);
	prices.push_back(6);
	prices.push_back(4);
	*/

	prices.push_back(4);
	prices.push_back(6);
	prices.push_back(3);
	prices.push_back(7);
	

	
	maxProfit::Solution s;
	int maxRes = s.maxProfit122_violence(prices);
	//maxRes = s.maxProfit122_dongtaiguihua(prices);

	getchar();
	return 0;
}

