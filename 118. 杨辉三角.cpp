#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows);
		for(int i = 0; i < numRows; i++)
		{
			result[i].resize(i+1);
			result[i][0] = result[i][i] = 1;
			for(int j = 1; j < i; j++)
			{
				result[i][j] = result[i-1][j-1] + result[i-1][j];
			}
		}
		return result;
	}

	vector<int> getRow(int rowIndex) {
		vector<vector<int>> pascalT(rowIndex+1);
		for(int i = 0; i <= rowIndex; i++)
		{
			pascalT[i].resize(i+1);
			pascalT[i][0] = pascalT[i][i] = 1;
			for(int j = 1; j < i; j++)
			{
				pascalT[i][j] = pascalT[i-1][j-1] + pascalT[i-1][j];
			}
		}
		return pascalT[rowIndex];
	}
};

int main118()
{

	return 0;
}