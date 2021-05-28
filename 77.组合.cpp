#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
输入: [1,2,3]
输出:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> tmp;

		getCombine(result, tmp, 1, n, k);

		return result;
	}

	void getCombine(vector<vector<int>>& result, vector<int>& tmp, int start, int n, int k) {
		if (k == 0) {
			result.push_back(tmp);
			return;
		}

		for (int i = start; i <= n; i++) {
			tmp.push_back(i);
			getCombine(result, tmp, i+1, n, k-1);
			tmp.pop_back();
		}
	}
};


int mainCombine()
{
	vector<vector<int>> res;

	Solution s;
	res = s.combine(4,2);

	vector<vector<int>>::iterator iter = res.begin();
	for (iter; iter != res.end(); iter++)
	{
		vector<int>::iterator it = iter->begin();
		for (it; it != iter->end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}