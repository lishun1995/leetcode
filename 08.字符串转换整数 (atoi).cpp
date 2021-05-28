#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


class Solution01 {
public:
	int myAtoi(string str)
	{
		int index = 0,res = 0,sign = 0;
		int total = 0;
		int digit = 0;
		if(str == "")
			return 0;

		while(str.at(index) == ' ' && index < str.length() - 1)
		{
			index++;
		}

		if(str.at(index) == '+' || str.at(index) == '-')
		{
			sign = str.at(index) == '+' ? 1 : -1;
			index++;
		}
		else
		{
			sign = 1;
		}

		while (index < str.size() )
		{
			digit = str.at(index) - '0';
			if(digit < 0 || digit > 9)
				break;
			//if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if(total > INT_MAX/10 || total == INT_MAX/10 && digit > INT_MAX%10)
				return sign == 1 ? INT_MAX : INT_MIN;
			
			total = total * 10 + digit;
			index++;
		}
		res = total * sign;
		return res;
	}
};

int mainmyAtoi()
{
	//string str = "abcd";  
	//int len = str.size(); //4
	//int min = INT_MAX%10; //7

	string str = " 90";  
	Solution01 so;
	int  res = so.myAtoi(str);

	getchar();
	return 0;
}