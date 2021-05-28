#include <iostream>
#include<sstream>
#include <string>
#include<vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

const string globalLetterMap[10] = {
	"",     //0 （程序运行过程中不会访问到，这里添加是为了访问letterMap的时候键盘的数字正好对应数组中的索引号）
	"",    //1 （同上）
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

//一般情况下，int类型的全局变量在不给初始值的时候会默认为0；int类型的局部变量不给初始值的时候会是一个随机的值
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