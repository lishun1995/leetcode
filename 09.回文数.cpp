#include <iostream>
#include<sstream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		
		if(x < 0 || ((x%10)==0 && x != 0))
			return false;

		int rev = 0;
		while(x > rev)
		{
			rev = rev * 10 + x % 10;
			x = x / 10;
		}
		
		return rev == x || x == int(rev/10);   
	}
};

int mainHWS()
{
	int x = 54145;
	Solution s;
	cout << s.isPalindrome(x) << endl;

	system("pause");
	return 0;
}