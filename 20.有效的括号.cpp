#include <stack>
#include <string>
#include <iostream>
using namespace std;

class solution
{
public:
	bool isValue(string s)
	{
		stack<char> strStack;
		for (int i = 0;i < s.size(); i++)
		{
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')
				strStack.push(s[i]);
			else
			{
				if(strStack.size() == 0)
					return false;
				
				char match;
				if(s[i] == ')')
					match = '(';
				else if(s[i] == ']')
					match = '[';
				else if(s[i] == '}')
					match = '{';

				char c = strStack.top();
				strStack.pop();

				if(match != c)
					return false;
			}
		}
		if(strStack.size() != 0)
			return false;

		return true;
	}

};

int mainLL()
{
	solution s;
	bool rs = s.isValue("([(){{}()])");
	


	getchar();
	return 0;
}

