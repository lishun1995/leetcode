#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode* dummy = new ListNode(0);  
		ListNode* pre = dummy;
		dummy->next = head;

		while(pre->next && pre->next->next)
		{
			ListNode* t = pre->next->next;
			pre->next->next = t->next;
			t->next = pre->next;
			pre->next = t;
			pre = t->next;
		}
		return dummy->next;
	}
};