#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：

第 i 位的数字能被 i 整除
i 能被第 i 位上的数字整除
现在给定一个整数 N，请问可以构造多少个优美的排列？

示例1:

输入: 2
输出: 2
解释: 

第 1 个优美的排列是 [1, 2]:
第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除

第 2 个优美的排列是 [2, 1]:
第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
说明:

N 是一个正整数，并且不会超过15。
*/


class Solution {
public:
	int countArrangement(int N) {
		int res = 0;
		map<int,int> selected;

		getCountArrangement(res,selected,N,1);
		return res;
	}

	void getCountArrangement(int &res,map<int,int> &selected,int N,int index)
	{
		if(index > N)
		{
			res++;
			return;
		}

		for(int i = 1 ; i < N + 1; i++)
		{
			if(selected[i - 1] != 0)
				continue;
			if((index % i) != 0 && (i % index) != 0)
				continue;
			selected[i - 1] = 1;
			getCountArrangement(res,selected,N,index + 1);
			selected[i - 1] = 0;
		}
	}
};

int main555()
{
	int N = 3;
	int res = 0;

	Solution s;
	res = s.countArrangement(N);

	cout << res << endl;

	getchar();
	return 0;
} 