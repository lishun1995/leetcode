#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */
vector<vector<int>> inputMatrix;

bool knows(int a, int b)
{
	if(inputMatrix[a][b] == 1)
		return true;
	return false;
}

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0) return 0;
		int k = 0;
		for(int i = 1; i < n; i++)
		{
			k = knows(i,k)?k:i;  
		}
		for(int i = 0; i < n; i++)
		{
			if(i != k && (knows(k,i) || !knows(i,k)))
				return -1;
		}
		return k;
    }
};

int main277()
{
	
	return 0;
}