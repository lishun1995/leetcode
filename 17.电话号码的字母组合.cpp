#include <iostream>
#include<sstream>
#include <string>
#include<vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

const string globalLetterMap[10] = {
	"",     //0 ���������й����в�����ʵ������������Ϊ�˷���letterMap��ʱ����̵��������ö�Ӧ�����е������ţ�
	"",    //1 ��ͬ�ϣ�
	"abc",  //2
	"def",  //3
	"ghi",  //4
	"jkl",  //5
	"mno",  //6
	"pqrs", //7
	"tuv",  //8
	"wxyz"  //9
};

class Solution {
public:
	void findCombination(const string &digits,int index ,const string &s)
	{
		if(index == digits.size())
		{
			res.push_back(s);
			return;
		}
		char c = digits[index];
		string letters = globalLetterMap[c - '0'];
		for (int i = 0; i < letters.size(); i++)
		{
			findCombination(digits,index + 1,s + letters[i]);
		}
			

	}

	vector<string> letterCombinations(string digits) {
		res.clear();
		if(digits == "")
			return res;
		findCombination(digits,0,"");
		return res;
	}

private:
	vector<string> res;
	static int i;
};

//һ������£�int���͵�ȫ�ֱ����ڲ�����ʼֵ��ʱ���Ĭ��Ϊ0��int���͵ľֲ�����������ʼֵ��ʱ�����һ�������ֵ
int mainffg()
{
	//string name[5]={"Zhang","Li","Fun","Wang","Tan"};	
	Solution s;
	string digits = "249";
	vector<string> res = s.letterCombinations(digits);

	int len = res.size();
	//cout << len << endl;
	vector<string>::iterator it = res.begin();
	for (; it < res.end(); it++)
	{
		cout << *it << endl;
	}

	//int i;  //-839923840
	//string str; //""
	
	getchar();
	return 0;
}