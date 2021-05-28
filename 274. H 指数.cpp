#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	//0 1 2 3 4 5 6
	//5 4 3 2 1 0 0
	int hIndex(vector<int>& citations) {
		if(citations.size() == 0) return 0;
		sort(citations.begin(),citations.end(),greater<int>());
		for(int i = 0; i < citations.size(); i++)
		{
			if(citations[i] < i+1)
				return i;
		}
		//{
		//	int i = 0;
		//	while(i < citations.size() && citations[citations.size() - 1 - i] >= i+1)
		//	{
		//		i++;
		//	}
		//}
		return citations.size();
	}

	//0 1 2 3 4 5 6
	//0 0 1 2 3 4 5 
	int hIndex2(vector<int>& citations) {
		if(citations.size() == 0) return 0;
		int n = citations.size();
		for(int i = 0; i < n; i++)
		{
			if(citations[i] >= n - i)
				return n - i;
		}
		return 0;
	}
};
// 8 7 6 5 4 3 2 1
// 1 2 3 4 5 6 7 8 
int main274()
{ 
	vector<int> res(10);

	int i1 = 7 >> 1; //3
	int i2 = 8 >> 1; //4
	int i9 = 9 >> 1; //4
	return 0;
} 