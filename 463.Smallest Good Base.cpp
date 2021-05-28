#include <math.h>
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;
string smallestgoodbase(string n)
{
	LL num = stol(n);
	LL ans = num - 1;
	for(int s = 60; s > 0; s--)
	{
		LL k = pow(num,1.0/s);
		LL cur_sum = 1,temp = k;
		if(k > 1)
		{
			for (int i = 1 ; i <= s; i++)
			{
				cur_sum = cur_sum + temp;
				if(LONG_MAX/k > temp)
				{
					temp = temp * k;
				}
			}
			if(cur_sum == num)
			{
				ans = k;
				break;
			}
		}
	}
	return to_string(ans);
}

int main483()
{
	smallestgoodbase("40");
	return 0;
}