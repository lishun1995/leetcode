#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int s1Len = s1.length();
		int s2Len = s2.length();

		if(s1Len > s2Len)
			return false;

		vector<int> map1(26),map2(26);

		for(int i = 0; i < s1Len; i++)
		{
			map1[s1[i] - 'a']++;
			map2[s2[i] - 'a']++;
		}

		if(map1 == map2)
		{
			return true;
		}

		for (int i = 0; i < s2Len - s1Len; i++)
		{
			map2[s2[i] - 'a']--;
			map2[s2[i+s1Len] - 'a']++;
			if(map1 == map2)
				return true;
		}

		return false;
	}
};

int maincheck()
{
	string str1 = "aba";
	string str2 = "asdfabaskdjfk";
	Solution s;
	bool result = s.checkInclusion(str1,str2);
	cout << result << endl;

	vector<int> map1(26),map2(26);

	for (int i = 0; i < str1.length(); i++)
	{
		map1[str1[i] - 'a']++;
	}

	vector<int>::iterator it = map1.begin();
	for (; it != map1.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}