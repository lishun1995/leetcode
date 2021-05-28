#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�

���磬���� n = 3�����ɽ��Ϊ��

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

class Solution {
public:
	vector<string> generateParenthesis(int n){
	    vector<string> res;

	    parenthesesGenerator(res,"",0,0,n);

		return res;
	}

	/*
	( (( ((( ((() ((()) ((()))
	(() (()( (()() (()())
	(()) (())( (())()
	() ()( ()(( ()(() ()(())
	()() ()()( ()()()
	*/
	void parenthesesGenerator(vector<string> &res,string str,int close,int open,int max)
	{
		//cout << str << " ";

		if(str.size() == 2 * max)
		{
			res.push_back(str);
			//cout << endl;
		}

		if(close < max)
		{
			parenthesesGenerator(res,str + '(',close + 1,open,max);
		}

		if(open < close)
		{
			parenthesesGenerator(res, str + ')',close,open + 1,max);
		}
	}
};


int maingenerateParenthesis()
{
	Solution s;
	vector<string> res = s.generateParenthesis(8);

	vector<string>::iterator it = res.begin();

    cout << endl; 

	for (it; it != res.end();it++)
	{
		cout << *it << endl;
	}

	getchar();
	return 0;
}