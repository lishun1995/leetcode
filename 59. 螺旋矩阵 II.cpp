#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���

ʾ��:

����: 3
���:
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
		int columnBegin = 0; //��
		int rowBegin = 0;    //��
		int columnEnd = n - 1;
		int rowEnd = n - 1;

		while(columnBegin <= columnEnd && rowBegin <= rowEnd)
		{
			//������
			for(int a = columnBegin; a <= columnEnd; a++)
			{
				res[rowBegin][a] = value++;
			}

			//���ϵ���
			for(int b = rowBegin + 1; b <= rowEnd; b++)
			{
				res[b][columnEnd] = value++;
			}

			if (columnBegin < columnEnd && rowBegin < rowEnd)
			{
				//���ҵ���
				for (int c = columnEnd - 1; c > columnBegin; c--)
				{
					res[rowEnd][c] = value++;
				}

				//���µ���
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