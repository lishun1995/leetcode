#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int __max = array[0];
		int currentMax = __max;

		for(int i = 1; i < array.size(); i++)
		{
			if(currentMax + array[i] > array[i])
			{
				__max = max(__max,currentMax + array[i]);
				//__max =  currentMax + array[i];
				currentMax = currentMax + array[i];
			}
			else
			{
				__max = max(__max,array[i]);
				//__max = array[i];
				currentMax = array[i];
			}
		}

		return __max;
	}
};

int maind()
{
	vector<int> array;
	array.push_back(1);
	array.push_back(-2);
	array.push_back(3);
	array.push_back(10);
	array.push_back(4);
	array.push_back(7);
	array.push_back(2);
	array.push_back(-5);

	Solution s;
	s.FindGreatestSumOfSubArray(array);

	getchar();
	return 0;
}