#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�

����԰�����˳�򷵻ش𰸡�

ʾ�� 1��

���룺["bella","label","roller"]
�����["e","l","l"]
ʾ�� 2��

���룺["cool","lock","cook"]
�����["c","o"]
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