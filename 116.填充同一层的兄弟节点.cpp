#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
using namespace std;

class Node
{
public:
	int val;
	Node* left;
	Node* next;
	Node* right;

	Node():val(0),left(NULL),next(NULL),right(NULL){}
	Node(int _val):val(_val),left(NULL),next(NULL),right(NULL){}
	Node(int _val,Node* _left,Node* _next,Node* _right):val(_val),left(_left),next(_next),right(_right){}
};

class Tree
{
public:
	void LevelTraversal(Node* root)
	{
		if(root == nullptr)
			return;

		printf("%d  ",root->val);
		LevelTraversal(root->left);
		LevelTraversal(root->right);
		return;
	}

	void conn(Node* root)
	{
		if(root == nullptr)
			return;

		if(root->left)  printf("%d ",root->left->val);
		if(root->right) printf("%d ",root->right->val);
		conn(root->left);
		conn(root->right);
		return;
	}

	void connIteration(Node* root)
	{
		if(!root) return;
		queue<Node*> q;
		q.push(root);
		q.push(NULL);

		while(true)
		{
			Node* cur = q.front();
			q.pop();
			if(cur)
			{
				printf("%d ",cur->val);
				cur->next = q.front();
				if(cur->left) q.push(cur->left);
				if(cur->right) q.push(cur->right);
			}
			else
			{
				if(q.size() == 0) return;
				q.push(NULL);
			}
		}
		return;

	}

	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		levelorder(root, 0,res);
		return res;
	}
	void levelorder(Node* node, int level,vector<vector<int>>& res) {
		if (!node) return;
		vector<int> tmp;
		if (res.size() == level) res.push_back(tmp);
		res[level].push_back(node->val);
		if (node->left) levelorder(node->left, level + 1,res);
		if (node->right) levelorder(node->right, level + 1,res);
	}
};

class StringBack 
{
public:
	bool backspaceCompareOn(string S,string T)
	{
		stack<char> s;
		stack<char> t;
		for(int i = 0; i < S.size(); i++)
		{
			if(S[i] != '#')
				s.push(S[i]);
			else if(!s.empty())
				s.pop();
		}
		for(int j = 0; j < T.size(); j++)
		{
			if(T[j] != '#')
				t.push(T[j]);
			else if(!t.empty())
				t.pop();
		}

		if(s.size() != t.size())
			return false;

		while(!s.empty())
		{
			if(s.top() != t.top())
				return false;
			s.pop();
			t.pop();
		}
		return true;
	}

	bool backspaceCompareO1(string S, string T) 
	{
		int i = S.length() - 1;
		int j = T.length() - 1;
		while (true)
		{
			for(int back = 0; i >= 0 && (back > 0 || S[i] == '#'); i--)
			{
				back += (S[i] == '#') ? 1 : -1;
			}
			for(int back = 0; j >= 0 && (back > 0 || T [j] == '#'); j--)
			{
				back += (T[j] == '#') ? 1 : -1;
			}
			if(i >= 0 && j >= 0 && S[i] == T[j])
			{
				i--;j--;
			}
			else
				return i == -1 && j == -1;
		}
	}
};

int main116()
{
	Node *node8 = new Node(8);
	Node *node9 = new Node(9);
	Node *node10 = new Node(10);
	Node *node11 = new Node(11);

	Node *node12 = new Node(12);
	Node *node13 = new Node(13);
	Node *node14 = new Node(14);
	Node *node15 = new Node(15);

	Node *node4 = new Node(4,NULL,NULL,NULL);
	Node *node5 = new Node(5,NULL,NULL,NULL);
	Node *node6 = new Node(6,NULL,NULL,NULL);
	Node *node7 = new Node(7,NULL,NULL,NULL);


	Node *node2 = new Node(2,node4,NULL,node5);
	Node *node3 = new Node(3,node6,NULL,node7);
	Node *node1 = new Node(1,node2,NULL,node3);


	Tree tree;
	//tree.conn(node1);
	//tree.connIteration(node1);
	//vector<vector<int>> res = tree.levelOrder(node1);

	//S = "ab#c", T = "ad#c"
	string S = "acb#a"; 
	string T = "ab#c";

	StringBack s;
	bool res = s.backspaceCompareO1(S,T);

	getchar();
	return 0;
}