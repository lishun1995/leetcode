#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


class Solution {
public:
	 vector<int> spiralOrder(vector<vector<int>>& matrix) 
	 {
		 vector<int> res;

		if(matrix.empty())
		{
			return res;
		}

		int columnBegin = 0,columnEnd = matrix[0].size() -1 ; //矩阵列总数  columnBegin表示每一层中每一行首，columnEnd表示每一行尾
		int rowBegin = 0,rowEnd = matrix.size() - 1 ; // 矩阵行总数   rowBegin表示每一层中每一列首，rowEnd表示每一列尾

		while(columnBegin <= columnEnd && rowBegin <= rowEnd)
		{
			//从左到右
			for (int a = columnBegin; a <= columnEnd; a++)
			{
				res.push_back(matrix[rowBegin][a]);
			}

			//从上到下
			for (int b = rowBegin + 1; b <= rowEnd; b++)
			{
				res.push_back(matrix[b][columnEnd]);
			}

			if(columnBegin < columnEnd && rowBegin < rowEnd)
			{
				//从右到左
				for (int c = columnEnd - 1; c > columnBegin; c--)
				{
					res.push_back(matrix[rowEnd][c]);
				}

				//从下到上
				for (int d = rowEnd; d > rowBegin; d--)
				{
					res.push_back(matrix[d][columnBegin]);
				}
			}

			columnBegin++,columnEnd--,rowBegin++,rowEnd--;
		}
		return res;
	 }
};

int main333()
{
	vector<vector<int>> nums(4,vector<int>(4,0));
	vector<int> result = Solution().spiralOrder(nums);

	system("pause");
	return 0;
}