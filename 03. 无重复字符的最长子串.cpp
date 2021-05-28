#include <hash_map>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{	
		int res = 0, left = 0, n = s.size();
		hash_map<char,int> m;
		for (int i = 0; i < n; i++)
		{
		left = max(left,m[s[i]]);
		m[s[i]] = i + 1;
		res = max(res,i - left + 1);
		}

		return res;

	}
};

int mainlengthOfLongestSubstring()
{
	Solution s;
	int i = s.lengthOfLongestSubstring("abcbca");

	string str = "D:/home/right"; //D:\home\right
	std::cout << str << endl;

	getchar();

	return 0;
}

