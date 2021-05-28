#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Solution02 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty()) return "null";
		for (int i = 0; i < strs[0].size(); i++)
		{
			for (int j = 1; j < strs.size(); j++)
			{
				if(strs[j][i] != strs[0][i]) 
					return strs[0].substr(0,i);
			}
		}
		return strs[0];
	}
};

int main0304()
{
	vector<string> str;
	//str.push_back("flower");
	//str.push_back("flow");
	str.push_back("flight");
	Solution02 s;
	string commonPrefix = s.longestCommonPrefix(str);
	cout << commonPrefix << endl;

	getchar();
	return 0;
}