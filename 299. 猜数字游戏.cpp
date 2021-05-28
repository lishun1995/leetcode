#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	//执行用时 4ms
	string getHint(string secret, string guess) {
		int a = 0,b = 0;
		int iLen = secret.size();
		int ds[10];
		int dg[10];

		for(int i = 0; i < 10; i++)
		{
			ds[i] = 0;
			dg[i] = 0;
		}
		for(int i = 0; i < iLen; i++)
		{
			int x = secret[i] - '0';
			int y = guess[i] - '0';
			if(x == y)
				a++;
			ds[x]++;
			dg[y]++;
		}
		for(int i = 0; i < 10; i++)
		{
			b += min(ds[i],dg[i]);
		}
		return to_string(long long(a))+'A'+to_string(long long(b-a))+'B';
	}

	//执行用时 24ms
	string getHint2(string secret, string guess) {
		map<char,int> ciMmap;
		vector<char> vcGue;
		int count1 = 0,count2 = 0;
		for(int i = 0; i < secret.size(); i++)
		{
			if(secret[i] == guess[i])
				count1++;
			else
			{
				vcGue.push_back(guess[i]);
				if(ciMmap.find(secret[i]) == ciMmap.end())
					ciMmap[secret[i]] = 1;
				else
					ciMmap[secret[i]]++;
			}
		}

		for(int i = 0; i < vcGue.size(); i++)
		{
			char value = vcGue[i];
			if(ciMmap.find(value) != ciMmap.end() && ciMmap[value] != 0)
			{
				count2++;
				ciMmap[value]--;
			}
		}
		return to_string(long long(count1))+'A'+to_string(long long(count2))+'B';
	}
};

int main299()
{
	string secret = "1807";
	string guess = "7801";
	Solution s;
	string res = s.getHint2(secret,guess);

	return 0;
}