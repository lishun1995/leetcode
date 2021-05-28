//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <math.h>
//#include <map>
//using namespace std;
//
//const int N=20;   //最多放皇后的个数
//int q[N];         //i表示皇后所在的行号，
////q[i]表示皇后所在的列号
//int cont = 0;     //统计解的个数
//
//class solution
//{
//public:
//	vector<vector<string>> solveNQueens(int n) {
//		int queen[20];
//		vector<vector<string>> res;
//		vector<string> vecStr;
//
//		if(n == 0)
//			return res;
//
//		getSolveNQueens(res,vecStr,queen,1,n);
//
//		return res;
//	}
//
//	int isValid2(int *queen,int row,int column)
//	{
//		int temp = 1;
//		while(temp < row)
//		{
//			if(column == queen[temp] || abs(row - temp) == abs(column - queen[temp]))
//				return 0;
//			temp++;
//		}
//		return 1;
//	}
//
//	void valueQueen(vector<vector<string>> &res,vector<string> &vecStr,int *queen,int n)
//	{
//		for (int i = 1;i < n + 1; i++)
//		{
//			string str = "";
//			for (int j = 1; j < n + 1; j++)
//			{	
//				if(queen[i] == j)
//				{
//					str += "Q";
//				}
//				else
//				{
//					str += "."; 
//				}
//			}
//			vecStr.push_back(str);
//		}
//		res.push_back(vecStr);
//		vecStr.clear();
//	}
//
//	void getSolveNQueens(vector<vector<string>> &res,vector<string> &vecStr,int *queen,int row,int n)
//	{
//		if(row > n)
//		{
//			valueQueen(res,vecStr,queen,n);
//			return;
//		}
//
//     	//测试第i行每一列
//		for(int column = 1; column < n + 1; column++)
//		{
//			if(isValid2(queen,row,column))
//			{
//				queen[row] = column;
//				getSolveNQueens(res,vecStr,queen,row + 1,n);
//			}
//	    }	
//	}
//};
//
//int mainNhuah()
//{
//	vector<vector<string>>  res;
//
//	solution s;
//	res = s.solveNQueens(4);
//
//	vector<vector<string>>::iterator iter = res.begin();
//	for (iter; iter != res.end(); iter++)
//	{
//		vector<string>::iterator it = iter->begin();
//		for (it; it != iter->end(); it++)
//		{
//			cout << *it << " ";
//		}
//		cout << endl;
//	}
//
//	getchar();
//	return 0;
//}
//
