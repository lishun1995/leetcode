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

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
˵��:

���������ǿ��Ե�����������һ��λ�á�
*/

class Solution {
public:
	 int jump(vector<int>& nums)
	{
		//int len = nums.size();
		//vector<vector<int>> steps(len,nums[0]);

		vector<int> steps(nums.size(), nums[0]);
		int step = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (steps[step] >= nums.size() - 1) return step + 1;
			if (steps[step + 1] < i + nums[i]) steps[step + 1] = i + nums[i];
			if (steps[step] <= i) step++;
		}
		return step;
	}
};

int mainpsps()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(1);

	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(3);

	Solution s;
	int res = s.jump(nums);

	cout << res << endl;

	system("pause");
	return 0;
}