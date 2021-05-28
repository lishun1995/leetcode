#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ��λ�á�

ʾ�� 1:

����: [2,3,1,1,4]
���: true
����: ��λ�� 0 �� 1 �� 1 ��, Ȼ���� 3 ���������һ��λ�á�
ʾ�� 2:

����: [3,2,1,0,4]
���: false
����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�
*/

class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		int len = nums.size();
		int range = nums[0];

		for (int i =0; i <= range; i++)
		{
			if(i < len && i + nums[i] > range)
			{
				range = i + nums[i];
			}
		}

		if(range >= nums.size() - 1)
		{
			return true;
		}

		return false;
	}
};

int main3333()
{
	
	system("pause");
	return 0;
}