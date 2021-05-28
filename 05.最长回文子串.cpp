#include <iostream>
#include<sstream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	//把给点字符串的每个字符当作中心 向两边扩展
	string longestPalindrome(string s) {

		if(s == "")
			return "";

		int len = s.length();
		int maxLen = 0;
		int start = 0;

		if(len == 1)
			return s;

		//aba
		for (int i = 0; i < len; i++)
		{
			int j = i - 1;
			int k = i + 1;

			while(j >= 0 && k < len && s[j] == s[k])
			{
				if(k - j + 1 > maxLen)
				{
					maxLen = k -j + 1;
					start = j;
				}
				j--;
				k++;
			}
		}

		//abba
		for (int i = 0; i < len; i++)
		{
			int j = i;
			int k = i + 1;

			while(j >= 0 && k < len && s[j] == s[k])
			{
				if(k - j + 1 > maxLen)
				{
					maxLen = k -j + 1;
					start = j;
				}
				j--;
				k++;
			}
		}

		if(maxLen > 0)
		{
			return s.substr(start, maxLen);
		}else
		{
			return s.substr(0,1);
		}
	}
};

int mainLongestPalindrome()
{
	string s = "abbcbba";
	//string str = s.substr(1,3);

	Solution sol;
	string res = sol.longestPalindrome(s);
	cout << res << endl;

	return 0;
}