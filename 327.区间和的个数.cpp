#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
#include < set>
using namespace std;

typedef long long LL;

namespace countRangeSum{
	class Solution {
	public:
		int countRangeSumV1(vector<int>& nums, int lower, int upper) {
			//if(nums.size() == 1 && (nums[0] > lower || nums <= ))
			//	return 1;
			int result	= 0	;
			int nums_size = nums.size();

			vector<vector<long long>> sum(nums_size,vector<long long>(nums_size,0));
			for(int i = 0; i < nums_size; i++)
			{
				sum[i][i] = nums[i];
				if(sum[i][i] >= lower && sum[i][i] <= upper )
					result++;
			}

			for(int i = 0 ; i < nums_size; i++)
			{
				for(int j = i+1; j < nums_size; j++)
				{
					sum[i][j] = sum[i][j-1] + nums[j];
					if(sum[i][j] >= lower && sum[i][j] <= upper)
						result++;
				}
			}

			return result;
		}

		int countRangeSumV2(vector<int>& nums, int lower, int upper) {
			int result = 0;
			int nums_size = nums.size();
			vector<long long> sum(nums.size(),0);
			long long tmpValue = 0;

			for(int i = 0; i < nums_size; i++)
			{
			    tmpValue += nums[i];
				sum[i] = tmpValue;
			}

			for(int i = 0; i < nums_size; i++)
			{
				for(int j = i; j < nums_size; j++)
				{
					if(i == 0)
					{
						tmpValue = sum[j];
					}
					else
					{
					    tmpValue = sum[j] - sum[i-1];
					}

					if(tmpValue >= lower && tmpValue <= upper)
						result++;
				}
			}
			return result;
		}

		int countRangeSumV3(vector<int>& nums, int lower, int upper) {
			int result = 0;
			int nums_size = nums.size();

			for(int i = 0; i < nums_size; i++)
			{
				long long tmpValue = 0;
				for(int j = i; j < nums_size; j++)
				{
					tmpValue += nums[j];
					if(tmpValue >= lower && tmpValue <= upper)
						result++;
				}
			}
			return result;
		}

		int countRangeSumV4(vector<int>& nums, int lower, int upper) {
			int result = 0;
			int nums_size = nums.size();

			vector<LL> sum(nums_size,0);
			LL tmpValue = 0;

			for(int i = 0 ; i < nums_size; i++)
			{
				if(nums[i] >= lower && nums[i] <= upper)
					result++;
				tmpValue += nums[i];
				sum[i] = tmpValue;
			}

			for(int i = 1; i < nums_size; i++)
			{
				if(sum[i] >= lower && sum[i] <= upper)
					result++;
				for(int j = 0; j < i-1; j++)
				{
					tmpValue = sum[i] - sum[j];
				    if(tmpValue >= lower && tmpValue <= upper)
						result++;
				}
			}

			return result;
		}

		int countRangeSumV5(vector<int>& nums, int lower, int upper)
		{
			int result = 0;
			int n = nums.size();
			multiset<long long> S;
			S.insert(0);
			long long presum = 0;
			for(int i=0; i<n; i++)
			{
				presum += nums[i];
				result += distance(S.lower_bound(presum - upper),S.upper_bound(presum - lower));
				S.insert(presum);
			}
			return result;
		}
	};
}


using namespace std;
const int maxn=100000+10;
const int INF=2*int(1e9)+10;
#define LL long long
int cmd(int a,int b){
	return a>b;
}

int main327()
{
	int num[6]={1,2,4,7,15,34}; 
	sort(num,num+6);                           //按从小到大排序 
	int pos1=lower_bound(num,num+6,7)-num;    //返回数组中第一个大于或等于被查数的值 
	int pos2=upper_bound(num,num+6,7)-num;    //返回数组中第一个大于被查数的值
	cout<<pos1<<" "<<num[pos1]<<endl; //3 7
	cout<<pos2<<" "<<num[pos2]<<endl; //4 15
	sort(num,num+6,cmd);                      //按从大到小排序
	int pos3=lower_bound(num,num+6,7,greater<int>())-num;  //返回数组中第一个小于或等于被查数的值 
	int pos4=upper_bound(num,num+6,7,greater<int>())-num;  //返回数组中第一个小于被查数的值 
	cout<<pos3<<" "<<num[pos3]<<endl;  //2 7
	cout<<pos4<<" "<<num[pos4]<<endl;  //3 4


	//-2,5,-1
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(5);
	nums.push_back(-1);
	//nums.push_back(1);
	//nums.push_back(0);

	countRangeSum::Solution s;
	//int resV1 = s.countRangeSumV1(nums,-2,2);
	//int resV2 = s.countRangeSumV2(nums,-2,2);
	//int resV3 = s.countRangeSumV3(nums,-2,2);
	int resV4 = s.countRangeSumV4(nums,-2,2);
	int resV5 = s.countRangeSumV5(nums,-2,2);
	getchar();
	return 0;
}