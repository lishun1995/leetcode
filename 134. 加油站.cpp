#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gCount = 0;
		int iStart = 0;
		int cur = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			gCount += gas[i] - cost[i];
			//cur记录当前汽油量加上当前加油站的汽油量，并减去到达下一站所消耗的汽油量
			cur += gas[i] - cost[i];
			if(cur < 0)
			{
				iStart = i+1;
				cur = 0;
			}
		}
		return gCount<0?-1:iStart;
	}

	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
		if(gas.size() == 0) return -1;
		for(int i = 0; i < gas.size(); i++)
		{
			if(gas[i] >= cost[i])
			{
				int n = i;
				int cur = 0;
				while(n < gas.size())
				{
					cur += gas[n] - cost[n];
					if(cur < 0) 
						break;
					else
						n++;
				}
				if(cur < 0)
					continue;
				for(int j = 0; j <= i; j++)
				{
					cur += gas[j] - cost[j];
					if(cur < 0)
						break;
					if(j == i)
						return i;
				}
			}
		}
		return -1;
	}

	int canCompleteCircuit3(vector<int>& gas, vector<int>& cost) {
		for(int i = 0; i < gas.size(); i++)
		{
			if(gas[i] >= cost[i])
			{
				if(whetherEnouth(i,gas,cost)) return i;
			}
		}
		return -1;
	}

	bool whetherEnouth(int n,vector<int>& gas, vector<int>& cost)
	{
		int i = n;
		int cur = 0;
		while(i < gas.size())
		{
			cur += gas[i] - cost[i];
			if(cur < 0) return false;
			else i++;
		}
		for(int j = 0; j <= n; j++)
		{
			cur += gas[i] - cost[i];
			if(cur < 0) return false;
		}
		return true;
	}

};

int main134()
{
	string str = "";

	vector<int> gas,cost;
	gas.push_back(3);
	gas.push_back(3);
	gas.push_back(4);
	//gas.push_back(3);
	//gas.push_back(4);

	cost.push_back(3);
	cost.push_back(4);
	cost.push_back(4);
	//cost.push_back(5);
	//cost.push_back(1);

	Solution s;
	int res = s.canCompleteCircuit2(gas,cost);


	return 0;
}