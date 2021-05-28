#include <iostream>
#include <vector>
using namespace std;

/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转

输入: 123
输出: 321

输入: -123
输出: -321

输入: 120
输出: 21
*/

class Solution {
public:
	int reverse(int x) {
		//vector<int> vec;
		//int temp = 0;
		//
		//if(x == 0)
		//	return x;

		//if(x > 2147483647 || x < -2147483648)
		//	return 0;

		//if(x < 0)
		//{	
		//	x = 0 - x;	
		//	while(x)
		//	{
		//		int num = x % 10;
		//		vec.push_back(num);	
		//		x = x / 10;
		//	}
		//	for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		//	{
		//		if((temp * 10) < -2147483648)
		//			return 0;
		//		temp = (*it) + temp * 10;
		//	}
		//	return 0 - temp;
		//}

		//if(x > 0)
		//{
		//		while(x)
		//		{
		//			int num = x % 10;
		//			vec.push_back(num);	
		//			x = x / 10;
		//		}
		//		for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		//		{
		//			if((temp * 10) > 2147483647)
		//				return 0;
		//			temp = (*it) + temp * 10;
		//		}
		//		return temp;
		//}

		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

int mainReverse()
{

	Solution s;
	int res = s.reverse(283841);
	cout << res << endl;

	//int x = -152;
	//cout << x % 10 << " " << x / 10 << endl;//-2 -15

	system("pause");
	return 0;
}