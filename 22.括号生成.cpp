#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

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