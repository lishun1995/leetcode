#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution
{
public:
	int lcode243_ShortestDistance(vector<string>& s1,string word1,string word2)
	{
		int pos1 = -1;
		int pos2 = -1;
		int distance = s1.size() - 1;
		for (int i = 0; i < s1.size()-1; i++)
		{
			if(word1.compare(s1[i]) == 0)
			{
				pos1 = i;
				if(pos2 != -1 && distance > abs(pos2-pos1)) distance = abs(pos2 - pos1); 
			}
			else if(word2.compare(s1[i]) == 0)
			{
				pos2 = i;
				if(pos1 != -1 && distance > abs(pos2-pos1)) distance = abs(pos2 - pos1);
			}
		}
		return distance;
	}



	//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
	vector<int> singleNumbers(vector<int>& nums) {
		map<int,int> mapNum;
		map<int,int>::iterator mapNum_iter;
		vector<int> res;
		for(int i = 0; i < nums.size(); i++)
		{
			if(mapNum[nums[i]] == 0)
			{
				mapNum[nums[i]]  = 1;
			}
			else
			{
				mapNum[nums[i]]  += 1;
			}
		}
		mapNum_iter = mapNum.begin();
		for(mapNum_iter; mapNum_iter != mapNum.end(); mapNum_iter++)
		{
			if(mapNum_iter->second == 1)
			{
				res.push_back(mapNum_iter->first);
			}
		}
		return res;
	}
};


//1，3，5，7，1，3，5，9
int main_array()
{
	vector<int> vValue;
	vector<int> res;

	vValue.push_back(1);
	vValue.push_back(3);
	vValue.push_back(5);
	vValue.push_back(7);
	vValue.push_back(1);
	vValue.push_back(3);
	vValue.push_back(5);
	vValue.push_back(9);

	
	Solution s;
	res = s.singleNumbers(vValue);
	return 0;
}