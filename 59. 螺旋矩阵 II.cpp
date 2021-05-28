#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> res(n, vector<int>(n, 0));
		if(n <= 0)
			return res;

		int value = 1;
		int columnBegin = 0; //列
		int rowBegin = 0;    //行
		int columnEnd = n - 1;
		int rowEnd = n - 1;

		while(columnBegin <= columnEnd && rowBegin <= rowEnd)
		{
			//从左到右
			for(int a = columnBegin; a <= columnEnd; a++)
			{
				res[rowBegin][a] = value++;
			}

			//从上到下
			for(int b = rowBegin + 1; b <= rowEnd; b++)
			{
				res[b][columnEnd] = value++;
			}

			if (columnBegin < columnEnd && rowBegin < rowEnd)
			{
				//从右到左
				for (int c = columnEnd - 1; c > columnBegin; c--)
				{
					res[rowEnd][c] = value++;
				}

				//从下到上
				for (int d = rowEnd; d > rowBegin; d--)
				{
					res[d][columnBegin] = value++;
				}
			}

			columnBegin++;
			rowBegin++;
			columnEnd--;
			rowEnd--;
		}
		return res;
	}
};

int maindd()
{
	vector<vector<int>> res;
 
	Solution s;
	res = s.generateMatrix(3);

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

	system("pause");
	return 0;
}