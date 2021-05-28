#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution01 {
public: 
	vector<TreeNode*> allPossibleFBT(int N){
		vector<TreeNode *> res;
		if(N == 0)
		{
			return res;
		}

		if(N == 1)
		{
			TreeNode *node = new TreeNode(0);
			res.push_back(node);
			return res;
		}

		N = N - 1;
		int i = 0;
		for(i = 1; i <= N; i += 2)
		{
			//��ڵ���ܴ��ڵ�������(��������)
			vector<TreeNode *> LT = allPossibleFBT(i);
			//��ڵ���ܴ��ڵ�������(��������)
			vector<TreeNode *> RT = allPossibleFBT(N-i);

			//�����ܵ�����������ֵ�����ڵ����Һ���
			vector<TreeNode *>::iterator itLT = LT.begin();
			for (itLT; itLT < LT.end(); itLT++)
			{
				vector<TreeNode *>::iterator itRT = RT.begin();
				for (itRT; itRT < RT.end();itRT++)
				{
					TreeNode *root = new TreeNode(0);
					root->left = *itLT;
					root->right = *itRT;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};

int mainallPossibleFBT()
{
	vector<TreeNode *> res;
	Solution01 so;
	res = so.allPossibleFBT(7);
	cout << res.size();

	getchar();
	return 0;
}