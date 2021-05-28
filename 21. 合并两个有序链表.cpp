#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		if(l1 == NULL && l2 != NULL)
		{
			return l2;
		}
		else if(l2 == NULL && l1 != NULL)
		{
			return l1;
		}

	    ListNode *mergeRes = new ListNode(0);
		ListNode *current = mergeRes;

		while (l1 != NULL && l2 != NULL)
		{
			if(l1->val < l2->val)
			{
				ListNode *temp = new ListNode(0);
				temp->val = l1->val;
				l1 = l1->next;
				current->next = temp;
				current = temp;
			}
			else
			{
				ListNode *temp = new ListNode(0);
				temp->val = l2->val;
				l2 = l2->next;
				current->next = temp;
				current = temp;
			}
		}

		while(l1 != NULL)
		{
			ListNode *temp = new ListNode(0);
			temp->val = l1->val;
			l1 = l1->next;
			current->next = temp;
			current = temp;
		}

		while(l2 != NULL)
		{
			ListNode *temp = new ListNode(0);
			temp->val = l2->val;
			l2 = l2->next;
			current->next = temp;
			current = temp;
		}
		return mergeRes->next;
	}
};


int mainmergeTwoLists()
{

	ListNode *node1 = NULL;
	ListNode *node2 = NULL;
	ListNode *node3 = NULL;
	ListNode *node4 = NULL;
	ListNode *node5 = NULL;
	ListNode *node6 = NULL;

	node1 = new ListNode(-9);
	node2 = new ListNode(3);
	node3 = new ListNode(4);

	node4 = new ListNode(5);
	node5 = new ListNode(7);
	node6 = new ListNode(4);

	node1->next = node2;
	node2->next = NULL;
//	node2->next = node3;
//	node3->next = NULL;

	node4->next = node5;
	node5->next = NULL;
	//node5->next = node6;
	//node6 = NULL;

	Solution s;
	s.mergeTwoLists(node1,node4);

	getchar();
	return 0;
}