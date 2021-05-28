#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


class Solution01 {
public:
	static inline int match(string src, string pattern) 
	{
		int src_index = 0;
		int pattern_index = 0;
		int src_len = src.size();
		int pattern_len = pattern.size();

		//����next���飬����ʼ��
		int *next = (int *)malloc(pattern_len * sizeof(int));
		getNext(pattern,next,pattern_len);

		//ƥ����ѭ����
		while(pattern_index < pattern_len && src_index < src_len)
		{
			//����Ӧλ���ַ�ƥ��������һλ�������ƶ�pattern
			if(pattern_index == -1 || src[src_index] == pattern[pattern_index])
			{
				src_index++;
				pattern_index++;
			}
			else
			{
				pattern_index = next[pattern_index];
			}
		}

		//��pattern_indexδ�ﵽ��β������patternδ���ƥ�䡣���������ƥ��
		if(pattern_index >= pattern_len)
		{
			return src_index - pattern_index;
		}
		else
		{
			return -1;
		}
	}
	
	static inline void getNext(string pattern,int *next,int pattern_len)
	{
		int i = 0;
		int j = -1;
		next[0] = -1;

		while (i < pattern_len - 1)
		{
			if(j == -1 || pattern[i] == pattern[j])
			{
				next[++i] = ++j;
			}
			else
				j = next[j];
		}

		for (int i = 0; i < pattern_len; i++)
		{
			cout << "next" << "[" << i << "]" << next[i] << endl;
		}
	}
};

int mainStrStr()
{
	char src[] = "BBC ABCDAB ABCDABCDABDE";
	char pattern[] = "ABCDABD";

	Solution01 solution;
	int res = solution.match(src,pattern);

	std::cout << res << std::endl;

	getchar();
	return 0;
}