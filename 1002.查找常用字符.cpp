#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
*/

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> res;
		vector<int> cnt(26,100);

		for(int s_i = 0; s_i < A.size(); s_i++)
		{
			string str_value = A[s_i];
			vector<int> tmp(26,0);
			for(int c_i = 0; c_i < str_value.size(); c_i++)
			{
				tmp[str_value[c_i] - 'a']++;
			}

			for(int i = 0; i < 26; i++)
			{
				cnt[i] = min(cnt[i],tmp[i]);
			}
		}

		for(int i = 0; i < 26; i++)
		{
			for(int j = 0; j < cnt[i]; j++)
				res.push_back(string(1,i + 'a'));
		}

		return res;

	}


};