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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		/*if(head == NULL || n < 0)
		return NULL;

		ListNode *current = NULL;
		ListNode *dummy = new ListNode(0);

		current = head;
		dummy->next = head;

		int len = 0;

		while(current != NULL)
		{
		len++;
		current = current->next;
		}

		current = dummy;

		for(int i = 0; i < (len - n); i++)
		{
		current = current->next;
		}

		current->next = current->next->next;

		return dummy->next;*/

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *first = dummy;
		ListNode *second = dummy;

		for (int i = 0; i < n + 1; i++)
		{
			first = first->next;
		}

		while(first != NULL)
		{
			first = first->next;
			second = second->next;
		}

		second->next  =  second->next->next;
		return dummy->next;
	}
};


int mainremoveNthFromEnd()
{
	//ListNode *head = NULL;
	ListNode *node1 = NULL;
	ListNode *node2 = NULL;
	ListNode *node3 = NULL;
	ListNode *node4 = NULL;
	ListNode *node5 = NULL;

	//head =  new ListNode(0);
	node1 = new ListNode(1);
	node2 = new ListNode(2);
	node3 = new ListNode(3);
	node4 = new ListNode(4);
	node5 = new ListNode(5);

	//head->next = node1;
	node1->next = node2;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	Solution s;
	s.removeNthFromEnd(node1,2);


	getchar();
	return 0;
}