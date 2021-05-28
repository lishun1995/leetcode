#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode *head = new ListNode(0);
		 ListNode *p = head;

		 if(l1 == NULL  || l2 == NULL)
		 {
			 return NULL;
		 }

		 int add = 0;
		 while(l1 || l2)
		 {
			 int value;
			 if(l1 && l2)
			 {
			   value  = l1->val + l2->val + add;
			   l1 = l1->next;
			   l2 = l2->next;
			 }else if(l1)
			 {
				 value  = l1->val + add;
				 l1 = l1->next;
			 }else
			 {
				 value = l2->val + add;
				  l2 = l2->next;
			 }		
			 add = value / 10;
			 p->next = new ListNode(value % 10);
			 p = p->next;
			 if(value >= 10 && l1 == NULL && l2 == NULL)
			 {
				  p->next = new ListNode(add);
				  p = p->next;
			 }
		 }

		 ListNode *ret = head->next;
		 delete head;
		 return ret;
    }
};

int mainaddTwoNumbers()
{
	ListNode *l1 = new ListNode(9);
	ListNode *p1 = l1;
	p1->next = new ListNode(8);
	p1 = p1->next;
	//p1->next = new ListNode(3);
	//p1 = p1->next;

	ListNode *l2 = new ListNode(1);
	//ListNode *p2 = l2;
	//p2->next = new ListNode(6);
	//p2 = p2->next;
	//p2->next = new ListNode(4);
	//p2 = p2->next;
	Solution s;
	s.addTwoNumbers(l1,l2);


	system("pause");
	return 0;
}