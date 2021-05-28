#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

const int N=20;   //���Żʺ�ĸ���
int q[N];         //i��ʾ�ʺ����ڵ��кţ�
//q[i]��ʾ�ʺ����ڵ��к�
int cont = 0;     //ͳ�ƽ�ĸ���

class solution
{
public:
	int totalNQueens(int n) {
		int queen[20];
		int result = 0;
		//vector<vector<string>> res;
		//vector<string> vecStr;

		if(n == 0)
			return result;

		getTotalNQueen(result,queen,1,n);

		return result;
	}

	int isValid2(int *queen,int row,int column)
	{
		int temp = 1;
		while(temp < row)
		{
			if(column == queen[temp] || abs(row - temp) == abs(column - queen[temp]))
				return 0;
			temp++;
		}
		return 1;
	}

	void getTotalNQueen(int &result,int *queen,int row,int n)
	{
		if(row > n)
		{
			result++;
			return;
		}

		//���Ե�i��ÿһ��
		for(int column = 1; column < n + 1; column++)
		{
			if(isValid2(queen,row,column))
			{
				queen[row] = column;
				getTotalNQueen(result,queen,row + 1,n);
			}
		}	
	}
};

int maindfdf()
{
	int  res;

	solution s;
	res = s.totalNQueens(8);

	cout << res << endl;

	getchar();
	return 0;
}

