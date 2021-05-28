#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution01 {
public: 
	int maxArea(vector<int>& height) {
		int i= 0,j = 0;
		int value = 0;
		int bottom = 0;
		int res = 0;
		int len = height.size();

		if(len == 0 || len == 1)
		{
			return 0;
		}

		//res = max(mix(height[i],height[j]) * (j - i))
		for(i = 0,j = len - 1; i < j;)
		{
			value = height[i] < height[j] ? height[i] : height[j];
			bottom = value * (j - i);
			res = max(res,bottom);
			if(height[i] < height[j])
				i++;
			else
				j--;
		}
		return res;
	}
};

//[1,8,6,2,5,4,8,3,7]
int mainmaxArea()
{
	vector<int> height;
	height.push_back(1);
	height.push_back(8);
	height.push_back(6);
	height.push_back(2);
	height.push_back(5);
	height.push_back(4);
	height.push_back(8);
	height.push_back(3);
	height.push_back(7);

	Solution01 s;
	int res = s.maxArea(height);
	cout << res << endl;

	getchar();
	return 0;
}